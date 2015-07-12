#include <iostream>
#include <tr1/functional>

using namespace std;

class GameCharacter;

int defaultHealthCalc( const GameCharacter &gc , float);

class GameCharacter {
public:
    typedef std::tr1::function<float (const GameCharacter& , float)> HealthCalcFunc;

    explicit GameCharacter( HealthCalcFunc hcf = defaultHealthCalc )
        :health_func_(hcf) {}

    float healthValue( float param ) const {
        return health_func_(*this, param);
    }

private:
    HealthCalcFunc health_func_;
};


//计算方法,策略模式的不同实现
class GameLevel {
public:
    GameLevel(int a ):a_(a){}
    ~GameLevel(){}
    float health( const GameCharacter &, float param_f,int param_i) const {
        cout << param_f<<endl;
        cout << param_i <<endl;
        cout << a_ <<endl;
        cout << this <<endl;
        return 4.2;
    }

private:
    int a_;
};

class EvilBadGuy:public GameCharacter {
public:
    explicit EvilBadGuy( HealthCalcFunc hcf = defaultHealthCalc ):
        GameCharacter(hcf) {    
    } 
};

int main() {
    GameLevel *level= new GameLevel(3);
    EvilBadGuy ebg( std::tr1::bind(&GameLevel::health, 
                level, std::tr1::placeholders::_1,std::tr1::placeholders::_2,3) );

    cout << ebg.healthValue(3.14) <<endl;
}

