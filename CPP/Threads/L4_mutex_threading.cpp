#include<stdio.h>
#include<thread>
#include<chrono>
#include<vector>
#include<iostream>
#include<mutex> //for mutex
//Mutex is used to lock the shared resource so that only one thread can access it at a time
//If one thread is accessing the shared resource, other threads have to wait until the first thread releases the lock
//This is done to prevent data inconsistency
std::mutex mtx;
int Money=1000;
void AddMoney(int amount){
    mtx.lock(); //lock the shared resource
    Money+=amount;
    mtx.unlock(); //unlock the shared resource
}
int main(){
    std::thread t1(AddMoney,100);
    std::thread t2(AddMoney,200);
    t1.join();
    t2.join();
    std::cout<<"Total Money: "<<Money<<std::endl;
    return 0;
}