//Join(), detach(), detachable(), joinable() 
#include<stdio.h>
#include<thread>
#include<chrono>
#include<vector>
#include<iostream>

//join(): It is used to wait for a thread to finish its execution. When you call join() on a thread, the calling thread (usually the main thread) will block until the thread on which join() was called has completed its task. 
//This is useful when you want to ensure that a thread has finished before proceeding with further operations in the main thread.
void run1(int n){
    for(int i=0;i<n;i++)
    std::cout<<"Hello from run1 "<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
}
int main(){
    std::thread t1(run1,5);
    std::cout<<"before thread function"<<std::endl;
    
    t1.join(); //main thread will wait for t1 to finish its execution
    //double join() is not allowed, it will give error
    if(t1.joinable()) //to check if thread is joinable or not
    {    std::cout<<"Thread is joinable"<<std::endl;
        t1.join();
    }
    else
        std::cout<<"Thread is not joinable"<<std::endl;
    //
    std::cout<<"After thread function"<<std::endl;


    //detach(): It is used to separate a thread from the thread object that represents it. When you call detach() on a thread, the thread becomes independent and continues to run in the background, even if the thread object goes out of scope. This is useful when you want a thread to run independently without blocking the main thread.
    return 0;
}