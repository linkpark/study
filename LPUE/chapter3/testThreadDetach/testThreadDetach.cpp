#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <pthread.h>
#include <errno.h>

using namespace std;

void *thread(void *arg){
	cout << "in thread id=" << pthread_self() <<endl;
	sleep(2);
	pthread_detach(pthread_self());

	cout << "Hello World!" <<endl;
	sleep(2);

	return (void*)0;
}

int main(){
	pthread_t tid;
	if(pthread_create(&tid,NULL,thread,0) != 0){
		cout <<"pthread_create error!"<<endl;
		return 0;
	}

	int *r;
	//sleep(2);
	int s = pthread_join(tid,(void**)&r);

	if(s == EINVAL){
		cout << "join error!" << endl;
		return 0;
	}else{
		cout << r << endl;
	}

	cout << "in main thread,tid="<<pthread_self()<<endl;
	return 0;
}
