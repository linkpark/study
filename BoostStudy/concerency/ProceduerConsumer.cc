#include <deque>
#include <boost/thread.hpp>
#include <boost/thread/lock_factories.hpp>
#include <stdint.h>

using namespace std;

template< typename T >
class StdQueueChannel{
public:
    StdQueueChannel( uint64_t max_size ):max_size_(max_size){

    }

    virtual ~StdQueueChannel(){
    
    }

    bool IsEmpty() {
        return queue_.empty();
    }

    bool IsFull() {
        return queue_.size() == max_size_; 
    }

    void Put( T &x ) {
        {
            auto lock = boost::make_unique_locks(mu_);
            while( IsFull() ) {
                cout << "full waiting .. " << endl;
                cond_put_.wait(lock);
            }

            queue_.push_front(x);
        }

        cond_get_.notify_all();
    }

    void Get( T &x ) {
        {
            auto lock = boost::make_unique_locks(mu_);
            while( IsEmpty() ) {
                cout << "empty waiting .." <<endl;
                cond_get_.wait(lock);
            }

            x = queue_.back();
            queue_.pop_back();
        }
    } 

private:
    boost::mutex mu_;
    boost::condition_variable_any cond_put_;
    boost::condition_variable_any cond_get_;
    std::deque<T> queue_;
    
    uint64_t max_size_;
};

