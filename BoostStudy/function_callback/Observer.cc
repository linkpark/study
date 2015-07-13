#include <iostream>
#include <boost/signals2.hpp>
#include <boost/random.hpp>
#include <boost/bind.hpp>

using namespace std;

typedef boost::variate_generator<boost::rand48, boost::uniform_smallint<> > bool_rand;
bool_rand g_rand( boost::rand48(time(0)), boost::uniform_smallint<>(0,100) );

class ring {
public:
    /*在signal内部有对应槽的类型，slot_t*/
    /*对应槽表示回调函数应该满足的条件，返回值是void ，传入参数是void*/
    typedef boost::signals2::signal<void()> signal_t;
    typedef signal_t::slot_type slot_t;

    boost::signals2::connection connect( const slot_t &s ) {
        return alaram.connect( s );
    }

    void press() {
        cout << "Ring alarm... " << endl;
        alaram();
    }

private:
    signal_t alaram;
};

extern char const nurse1[] = "Marry";
extern char const nurse2[] = "Kate";

template<char const *name >
class nurse {
public:
    nurse():rand(g_rand){}

    void action(){
        cout << name;
        if ( rand() > 30 ) {
            cout << " wakeup and open the door. " <<endl;
        } else {
            cout << " is sleeping ... " <<endl;
        }
    }

private:
    bool_rand &rand;
};

extern char const baby1[] = "Tom";
extern char const baby2[] = "Jerry";

template<char const *name>
class baby {
private:
    bool_rand &rand;

public:
    baby():rand(g_rand) { }
    
    void action() {
        cout << "Baby" << name;
        if( rand() > 50 ) { 
            cout << " wakeup and crying loudly ..." << endl;
        } else {
            cout << " is sleeping sweetly ..." << endl;
        }
    }
};

class guest {
public:
    void press( ring &r ) {
        cout << " A guest press the ring." << endl;
        r.press();
    }
};

int main() {
    //声明门铃、护士、婴儿
    ring r;
    nurse<nurse1> n1;
    nurse<nurse2> n2;
    baby<baby1> b1;
    baby<baby2> b2;
    guest g;

    r.connect(boost::bind( &nurse<nurse1>::action, n1 ) );
    r.connect(boost::bind( &nurse<nurse2>::action, n2 ) );
    r.connect(boost::bind( &baby<baby1>::action, b1));
    r.connect(boost::bind( &baby<baby2>::action, b2));

    g.press(r);
}

