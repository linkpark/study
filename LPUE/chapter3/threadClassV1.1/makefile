testThread:main.cpp stadx.h CLMyThread.h CLThread.o CLStatus.o CLLogger.o
	g++ -g -o testThread main.cpp CLMyThread.h *.o -lpthread
	rm -rf *.o

CLStatus.o:CLStatus.cpp CLStatus.h
	g++ -g -c CLStatus.cpp

CLLogger.o:CLLogger.cpp CLLogger.h
	g++ -g -c CLLogger.cpp

CLThread.o:CLThread.h CLThread.cpp
	g++ -g -c CLThread.cpp

clean:
	rm -rf testThread
	rm -rf *.o

