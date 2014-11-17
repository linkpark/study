main: ArithmeticWorkItem.o FIFOChannel.o Thread.o ThreadPool.o ThreadWorkItem.o WorkThread.o ThreadPoolDispatcher.o
	g++ -g -o main main.cpp *.o -lpthread

ArithmeticWorkItem.o: ArithmeticWorkItem.h ArithmeticWorkItem.cpp
	g++ -g -c ArithmeticWorkItem.cpp

FIFOChannel.o:FIFOChannel.cpp FIFOChannel.h Channel.h
	g++ -g -c FIFOChannel.cpp

Thread.o:Thread.h Thread.cpp
	g++ -g -c Thread.cpp

ThreadPool.o:ThreadPool.h ThreadPool.cpp
	g++ -g -c ThreadPool.cpp

ThreadWorkItem.o:ThreadWorkItem.h ThreadWorkItem.cpp
	g++ -g -c ThreadWorkItem.cpp

WorkThread.o:WorkThread.h WorkThread.cpp
	g++ -g -c WorkThread.cpp

ThreadPoolDispatcher.o:ThreadPoolDispatcher.h ThreadPoolDispatcher.cpp
	g++ -g -c ThreadPoolDispatcher.cpp

clean:
	rm -rf *.o
	rm -rf main
	rm -rf *.fifo

