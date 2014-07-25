test: test.o f.o
	g++ -o test test.o f.o
	rm -rf *.o

test.o:test.cpp
	g++ -c test.cpp -o test.o

f.o:f.cpp
	g++ -c f.cpp -o f.o

clean:
	rm -rf test
	rm -rf *.o
