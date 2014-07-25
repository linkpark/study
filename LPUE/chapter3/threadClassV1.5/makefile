testThread:main.cpp stadx.h CLExecutiveFunctionProvider.o CLExecutive.o CLThread.o CLParaPrinter.o CLThread.o CLStatus.o CLLogger.o
	g++ -g -o testThread main.cpp *.o -lpthread
	rm -rf *.o

CLStatus.o:CLStatus.cpp CLStatus.h
	g++ -g -c CLStatus.cpp

CLLogger.o:CLLogger.cpp CLLogger.h
	g++ -g -c CLLogger.cpp

CLExecutiveFunctionProvider.o:CLExecutiveFunctionProvider.cpp CLExecutiveFunctionProvider.h
	g++ -g -c CLExecutiveFunctionProvider.cpp

CLExecutive.o:CLExecutive.h CLExecutive.cpp
	g++ -g -c CLExecutive.cpp

CLThread.o:CLThread.h CLThread.cpp
	g++ -g -c CLThread.cpp

CLParaPrinter.o:CLParaPrinter.cpp CLParaPrinter.h
	g++ -g -c CLParaPrinter.cpp

clean:
	rm -rf testThread
	rm -rf *.o

