#include <iostream>
#include <string>

using namespace std;

class LargeObject{
public:
    typedef int ObjectID;

public:
    LargeObject( ObjectID id );
    ~LargeObject() {} 

    const string& field1() const;
    int field2() const;
    double filed3() const;
    const string& field4() const;
    ObjectID getObjectID() const {
        return oid;
    }
    
private:
    ObjectID oid;
    
    /* 关键字mutable 是用来突破const限制的，
     * 在一些情况下例如demand-on-read需要突破这类的限制*/
    mutable string *fieldValue;
    mutable int *field2Value;
    mutable double *field3Value;
    mutable string *field4Value;
};

LargeObject::LargeObject( ObjectID id ):
    oid(id), fieldValue(0), field2Value(0),field3Value(0),field4Value(0){
}

const string& LargeObject::field1() const {
    if ( 0 == fieldValue ){
        fieldValue = new string( "field1" );
    }

    return *fieldValue;
}

int LargeObject::field2() const {
    if ( 0 == field2Value ){
        field2Value = new int(2);
    }

    return *field2Value;
}

double LargeObject::filed3() const {
    if ( 0 == field3Value ){
        field3Value = new double(3.3);
    }

    return *field3Value;
}

const string& LargeObject::field4() const {
    if ( 0 == field4Value ){
        field4Value = new string("field 4 Value ");
    }

    return *field4Value;
}

int main(){
    LargeObject obj(1);

    cout << obj.field4() <<endl;
    cout << obj.field1() <<endl;

    return 0;
}
