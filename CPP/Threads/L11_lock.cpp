#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>

//syntax std::lock(m1, m2, m3, ...);
//it locks all the mutexes passed to it in a deadlock free manner
//it is a blocking call
//it is a variadic function

//Example:0 --> No deadlock
//Thread -1         Thread -2
//std::lock(m1, m2)      lock(m1, m2)


//Example:1 --> No Deadlock
//Thread -1         Thread -2
//std::lock(m1, m2)      lock(m2, m1)

// Here is an example of using std::lock to avoid deadlock when multiple mutexes are involved.
// In this example, two threads attempt to lock two mutexes in different orders.
// By using std::lock, T1 is locking m1 and T2 is locking m2, In the meantime both threads are waiting for the other mutex to be released.
// This creates a deadlock situation. To avoid this, we use std::lock to lock both mutexes, It will re-arrange T1 locking scene.

//Example:2 --> Deadlock
//Thread -1         Thread -2
//std::lock(m1, m2)      lock(m3, m4)
//std::lock(m3, m4)      lock(m1, m2)

std::mutex m1, m2, m3, m4;

void task1() {
    std::cout << "Task 1 is trying to lock m1 and m2\n";
    while (1)
    {
        //std::lock(m1, m2); // locks both m1 and m2 without deadlock
        m1.lock();
        m2.lock();
        std::cout << "Task 1 has locked m1 and m2\n";

        // Simulate some work with the locked resources
        //std::this_thread::sleep_for(std::chrono::milliseconds(100));

        // Unlock the mutexes
        m1.unlock();
        m2.unlock();
    }
    std::cout << "Task 1 has unlocked m1 and m2\n";
}

void task2() {
    std::cout << "Task 2 is trying to lock m2 and m1\n";
    while(1)
    {
        //std::lock(m2, m1); // locks both m2 and m1 without deadlock
        m2.lock();
        m1.lock();
        std::cout << "Task 2 has locked m2 and m1\n";

        // Simulate some work with the locked resources
        //std::this_thread::sleep_for(std::chrono::milliseconds(100));

        // Unlock the mutexes
        m2.unlock();
        m1.unlock();
    }
    std::cout << "Task 2 has unlocked m2 and m1\n";
}


int main() {
    std::thread t1(task1);
    std::thread t2(task2);

    t1.join();
    t2.join();

    return 0;
}