#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>

// condition_variable
// A condition variable is a synchronization primitive that allows threads to wait for certain conditions to be met
// before proceeding with their execution. It is typically used in conjunction with a mutex to protect shared
// resources and ensure that only one thread can access the resource at a time.
// Condition variables are often used in producer-consumer scenarios, where one thread produces data and another
// thread consumes it. The producer thread can signal the consumer thread when new data is available,
// and the consumer thread can wait for the signal before attempting to access the shared resource.
// Condition variables can also be used to implement other synchronization patterns, such as barriers and
// reader-writer locks. They are a powerful tool for managing concurrency in multithreaded applications,
// but they can also be complex to use correctly. It is important to carefully design the synchronization
// logic and ensure that all threads are properly synchronized.
//notify_one() and notify_all()
//wait() - it will unlock the mutex and put the thread in waiting state until it is notified.
//wait_for() - it will unlock the mutex and put the thread in waiting state until it is notified or the specified time duration has passed.
//wait_until() - it will unlock the mutex and put the thread in waiting state until it is notified or the specified time point is reached.
#include<condition_variable>
std::condition_variable cv;
std::mutex mtx;
long balance = 0;

void AddMoney(int amount)
{
    std::lock_guard<std::mutex> lg(mtx);
    balance += amount;
    std::cout << "Added " << amount << ", new balance: " << balance << "\n";
    cv.notify_one(); // Notify one waiting thread
}

void WithdrawMoney(int amount)
{
    std::unique_lock<std::mutex> ul(mtx);
    // Wait until balance is sufficient
    cv.wait(ul, []{ return balance >= 100; }); // Lambda function to check the condition
    if (balance > amount)
    {
        balance -= amount;
        std::cout << "Withdrew " << amount << ", new balance: " << balance << "\n";
        /* code */
    }
    else
    {
        std::cout << "Insufficient balance to withdraw " << amount << "\n";
    }
    
    balance -= amount;
    std::cout << "Withdrew " << amount << ", new balance: " << balance << "\n";
}

int main()
{
    std::thread t1(WithdrawMoney, 300);
    std::this_thread::sleep_for(std::chrono::milliseconds(300)); // Ensure withdraw happens after add
    std::thread t2(AddMoney, 200);
    t1.join();
    t2.join();
    std::cout << "Final balance: " << balance << "\n";
    return 0;
}