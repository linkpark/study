/*
 * =================================================================
 *
 *            Filename:    Singleton.h
 *
 *         Description:    singleton template 
 *
 *             Version:    
 *             Created:    2015-07-02 16:31
 *           Reversion:    none
 *            Compiler:    g++
 *            
 *              Author:    wangjin, 836792834@qq.com
 * 
 * ==================================================================
 */
#include <pthread.h>
#include <tr1/memory>

template<class T>
class Singleton {
protected:
    Singleton(){ }

private:
    static void SingletonInit() {
        single_object_.reset( new T );
    }

public:
    virtual ~Singleton(){ }
    static std::tr1::shared_ptr<T> GetInstance() {
        if(NULL == single_object_.get()) {
            pthread_once(&once_, &SingletonInit); 
        }

        return single_object_;
    }
 
private:
    static std::tr1::shared_ptr<T> single_object_;
    static pthread_once_t once_;
};

//using pthread_once() the keep multi thread safe
template<class T>
pthread_once_t Singleton<T>::once_ = PTHREAD_ONCE_INIT;

template<class T>
std::tr1::shared_ptr<T> Singleton<T>::single_object_;

