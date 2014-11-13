DIR_COMM = ./comm
COMM_OBJ = $(wildcard ${DIR_COMM}/*.o)

MasterMain: MasterMain.cpp MasterAgent.o SlaveAgent.o WordCountMain
	g++ -g -o MasterMain MasterMain.cpp MasterAgent.o SlaveAgent.o ${COMM_OBJ}

WordCountMain: WordCountClientAgent.o WordCountMain.cpp
	g++ -g -o WordCountMain WordCountMain.cpp WordCountClientAgent.o ${COMM_OBJ}

MasterAgent.o: MasterAgent.h MasterAgent.cpp
	g++ -g -c MasterAgent.cpp

SlaveAgent.o: SlaveAgent.cpp SlaveAgent.h
	g++ -g -c SlaveAgent.cpp

WordCountClientAgent.o: WordCountClientAgent.h WordCountClientAgent.cpp
	g++ -g -c WordCountClientAgent.cpp

clean:
	rm -rf *.o
	rm -rf MasterMain
	rm -rf WordCountMain

