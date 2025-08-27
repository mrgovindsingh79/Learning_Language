//timed_mutex.cpp
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

int Amount = 0;
std::timed_mutex mtx;
void AddAmount(int i)
{
    if(mtx.try_lock_for(std::chrono::milliseconds(200)))
    {
        Amount ++;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "Thread " << i << " added " << i << ", total Amount: " << Amount << "\n";
        mtx.unlock();
    }
    else
    {
        std::cout << "Thread " << i << " could not lock the mutex within 100 milliseconds.\n";
    }
}

//try_lock_until
//std::chrono::steady_clock::now() + std::chrono::milliseconds(200) 
void AddAmount2(int i)
{
    if(mtx.try_lock_until(std::chrono::steady_clock::now() + std::chrono::milliseconds(200)))
    {
        Amount ++;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "Thread " << i << " added " << i << ", total Amount: " << Amount << "\n";
        mtx.unlock();
    }
    else
    {
        std::cout << "Thread " << i << " could not lock the mutex within 100 milliseconds.\n";
    }
}
int main(){
    std::thread t1(AddAmount, 1);
    std::thread t2(AddAmount, 2);
    //std::thread t1(AddAmount2, 1);
    //std::thread t2(AddAmount2, 2);
    t1.join();
    t2.join();


    return 0;

}   