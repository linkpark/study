test: AbstractAttributeVector.o BaseAttributeVector.h BitCompressedVector.h
	g++ -g -o test test.cpp AbstractAttributeVector.o BaseAttributeVector.h	BitCompressedVector.h -std=c++11
	rm -rf *.o

AbstractAttributeVector.o: AbstractAttributeVector.h AbstractAttributeVector.cpp
	g++ -g -c AbstractAttributeVector.cpp -std=c++11

clean:
	rm -rf test
	rm -rf *.o

