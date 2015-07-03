#include "ObjectFactory.h"
#include "Object.h"
#include <tr1/memory>

using namespace std;

int main(){
    string name1("abc");
    string name2("bcd");
    
    tr1::shared_ptr<Object> obj1;
    tr1::shared_ptr<Object> obj2;
    tr1::shared_ptr<Object> obj3;

    obj1 = ObjectFactory::GetInstance()->GetObject(name1);
    obj2 = ObjectFactory::GetInstance()->GetObject(name2);
    obj3 = ObjectFactory::GetInstance()->GetObject(name1);

    return 0;
}
