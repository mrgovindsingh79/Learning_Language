#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
//unique_lock
//syntax std::unique_lock<mutex_type> lock(mutex, std::defer_lock);
//Locking strategies
//1. std::defer_lock: The mutex is not locked upon construction. You can lock it later using lock() method.
//2. std::try_to_lock: The mutex is attempted to be locked upon construction. If the lock is not acquired, the unique_lock object will not own the mutex.
//3. std::adopt_lock: The mutex is assumed to be already locked by the current thread. The unique_lock object will take ownership of the mutex without attempting to lock it again.
//A unique_lock is more flexible than a lock_guard because it allows for manual locking and unlocking of

int buffer = 0;
std::mutex mtx;

void task(const char* thread, int count)
{
    std::unique_lock<std::mutex> lock(mtx); //Automaticall Mutex is locked
    
    for(int i = 0; i < count; ++i)
    {
        buffer += 1;
        std::cout << "Thread " << thread << " is executing iteration " << i << "\n";
    }
    lock.unlock(); // Manually unlock the mutex
    // You can also relock it if needed
    // lock.lock();
}

void task1(const char* thread, int count)
{
    std::cout <<"unique_lock with defer_lock\n";
    std::unique_lock<std::mutex> lock(mtx, std::defer_lock); // Mutex is not locked yet

    //Here we can n number of lines of code
    lock.lock(); // Manually lock the mutex
    for(int i = 0; i < count; ++i)
    {
        buffer += 1;
        std::cout << "Thread " << thread << " is executing iteration " << i << "\n";
    }
    //lock.unlock(); // Manually unlock the mutex is not required as it will be unlocked automatically when going out of scope
    // You can also relock it if needed
    // lock.lock();
}

int main()
{
    std::thread t1(task1, "A", 5);
    std::thread t2(task1, "B", 5);
    t1.join();
    t2.join();
    std::cout << "Final buffer value: " << buffer << "\n";
    return 0;
}