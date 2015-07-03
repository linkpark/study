#include <iostream>
#include <tr1/functional>

using namespace std;

class GameCharacter;

int defaultHealthCalc( const GameCharacter &gc );

class GameCharacter {
public:
    typedef std::tr1::function<int (const GameCharacter&)> HealthCalcFunc;

    explicit GameCharacter( HealthCalcFunc hcf = defaultHealthCalc )
        :health_func_(hcf) {}

    int healthValue() const {
        return health_func_(*this);
    }

private:
    HealthCalcFunc health_func_;
};

short calcHealth( const GameCharacter& ){
    return 1;
}

struct HealthCalculaor {
    int operator()( const GameCharacter& ) const {
        return 4;
    }
};

//计算方法,策略模式的不同实现
class GameLevel {
public:
    float health( const GameCharacter & ) const {
        return 4.2;
    }
};

class EvilBadGuy:public GameCharacter {
public:
    explicit EvilBadGuy( HealthCalcFunc hcf = defaultHealthCalc ):
        GameCharacter(hcf) {    
    } 
};

int main() {
    GameLevel level;
    EvilBadGuy ebg( std::tr1::bind(&GameLevel::health, 
                level, std::tr1::placeholders::_1) );

    cout << ebg.healthValue() <<endl;
}

