#ifndef OBJECTFACTORY_
#define OBJECTFACTORY_
#include "Object.h"
#include "Singleton.h"

#include <tr1/memory>
#include <map>

using namespace std;

class Object;
class ObjectFactory:public Singleton<ObjectFactory> {
    friend class Singleton<ObjectFactory>;

private:
    ObjectFactory() { }

public:
    ~ObjectFactory(){ 
    }

public:
    //this is also thread unsafe;
    tr1::shared_ptr<Object> GetObject( string name ) {
        if( factory_map_.count(name) == 0 ) {
            factory_map_[name].reset(new Object(name));
        }

        return factory_map_[name];
    }

private:
    map<string , tr1::shared_ptr<Object> > factory_map_;
};

#endif

