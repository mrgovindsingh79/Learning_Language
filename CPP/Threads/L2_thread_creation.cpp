#include<stdio.h>
#include<thread>
#include<chrono>
#include<vector>
#include<iostream>
//using namespace std;

//function pointer
void show(){
    std::cout<<"Hello World"<<std::endl;
}

class A{
    public:
    void run(int n){
        for(int i=0;i<n;i++)
        std::cout<<"Hello "<<std::endl;
    }
};
int main(){
    //function pointer
    //std::thread t1(show);
    //t1.join();

    //Non-static member function
    A obj;
    A obj2;
    std::thread t2(&A::run, &obj, 5); //&A::run is pointer to member function, &obj is the object of class A
    std::cout<<"In main function"<<std::endl;
    std::thread t3(&A::run, &obj2, 5); //&A::run is pointer to member function, &obj is the object of class A
    t2.join();
    t3.join();

    std::cout<<"End of main function"<<std::endl;
    return 0;
}