#include <iostream>
#include <cmath>
#include "BitCompressedVector.h"

using namespace std;

int main(int argc,char **argv){
    if(2 != argc){
        cout << "Useage:<test> <number of the vector>" <<endl;
        return 0;
    }
    
    size_t numberOfRows = static_cast<size_t>( atoi(argv[1]) );
    size_t bitWidth = static_cast<size_t>(log2l(numberOfRows) + 1) ;
    int value = 0;

    vector< size_t > bitsForEachColumn(2); 
    bitsForEachColumn[0] = bitWidth;

    BitCompressedVector< int > bitCompressedVector(1,numberOfRows,bitsForEachColumn);
    bitCompressedVector.allocData();
    
    for(size_t i = 0 ; i < numberOfRows ; i ++){
        bitCompressedVector.set(i,0,value);
        value++;
    }

    /*for(size_t i = 0; i < numberOfRows ; i ++){
        cout << bitCompressedVector.get(i,0) <<endl;
    }*/
    int originSize = sizeof(int) * numberOfRows;
    int compressedSize = bitCompressedVector.getSize();
    
    cout << "origin size is:" << originSize << "bytes" << endl;
    cout << "compressed size is:" << compressedSize << "bytes" <<endl;
    
    double rate = static_cast<double>(compressedSize) / static_cast<double>(originSize);

    cout << "compressed rate is:" << rate << endl;

    bitCompressedVector.clear();
    return 0;
}
