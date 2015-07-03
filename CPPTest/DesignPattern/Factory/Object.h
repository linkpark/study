#ifndef OBJECT_H_
#define OBJECT_H_
#include <iostream>
#include <string>

using namespace std;

class Object{
public:
    Object( string name ):name_(name) {}
    ~Object() {
        cout << "Object " << name_ <<" delete" <<endl;
    }

private:
    string name_;
};

#endif
