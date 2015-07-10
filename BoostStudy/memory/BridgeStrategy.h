#include <boost/smart_ptr.hpp>
#include <iostream>

using namespace std;

class Sample{
public:
    Sample();
    ~Sample() {}

    void print();   

private:
    class Impl;
    boost::shared_ptr<Impl> p_;
};

