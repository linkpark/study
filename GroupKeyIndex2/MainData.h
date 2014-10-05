#ifndef MAINDATA_H_
#define MAINDATA_H_
#include <vector>
#include <map>

#include "BitCompressedVector.h"

using namespace std;

template< class T >
class MainData{
public:
    vector< T >& getDic();
    BitCompressedVector< uint64_t >& getPositionVector();
    BitCompressedVector< uint64_t >& getIndexVector(); 
    BitCompressedVector< uint64_t >& setPositionVector();
    BitCompressedVector< uint64_t >& setIndexVector();

private:
    BitCompressedVector< uint64_t > m_IndexVector;
    BitCompressedVector< uint64_t > m_PositionVector;
    BitCompressedVector< uint64_t > m_AttributeVector;
    vector< T > m_Dictionary; 
};

#endif
