#include <iostream>

using namespace std;

class GameCharacter;

int defalutHealthCalc( const GameCharacter &gc ) {
    return 2;
}

class GameCharacter {
public:
    typedef int ( *HealthCalcFunc ) (const GameCharacter& );

    explicit GameCharacter( HealthCalcFunc hcf )
        :health_func_( hcf ) {
           
    }

    int healthValue() const {
        return health_func_( *this );
    }

private:
    HealthCalcFunc health_func_;
};

class EvilBadGuy:public GameCharacter {
public:
    explicit EvilBadGuy( HealthCalcFunc hcf ):
        GameCharacter(hcf) {    
    }
};

int loseHealthQuickly( const GameCharacter &gc ) {
    return 4;
}

int main(){
    GameCharacter b_class(defalutHealthCalc);
    EvilBadGuy d_class(loseHealthQuickly);

    cout<< b_class.healthValue() <<endl;
    cout<< d_class.healthValue() <<endl;
}
