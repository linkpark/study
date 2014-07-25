testLogger: stadx.h main.cpp CLStatus.o CLLogger.o
	g++ -g -o testLogger main.cpp *.o
	rm -rf *.o

CLStatus.o: CLStatus.h CLStatus.cpp
	g++ -g -c CLStatus.cpp

CLLogger.o: CLLogger.h CLLogger.cpp
	g++ -g -c CLLogger.cpp

clean:
	rm -rf testLogger
