#include<stdio.h>
#include<thread>
#include<chrono>
#include<mutex>
#include<iostream>

int counter=0;
std::mutex mtx;
//try_lock() function is used to lock the mutex only if it is not already locked by another thread
//if it is already locked, it will return false and the thread will not be blocked
//if it is not locked, it will lock the mutex and return true
void increase_counter_10K(char thread_id)
{

    for(int i=0;i<1000000;i++)
    {
        //std::cout<<thread_id;
        if(mtx.try_lock())
        {
            counter++;
            mtx.unlock();
        }
    }
}
int main()
{
    std::thread t1(increase_counter_10K,'A');
    std::thread t2(increase_counter_10K,'B');
    t1.join();
    t2.join();
    std::cout<<"Final counter value: "<<counter<<std::endl;

    return 0;
}