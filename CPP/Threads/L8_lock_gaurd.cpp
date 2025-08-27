#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
// lock_guard
// A lock guard is a C++ standard library feature that provides a convenient way to manage mutexes in a multithreaded environment.
// It is a wrapper around a mutex that automatically locks the mutex when the lock guard is created and unlocks it when the lock guard goes out of scope.
// This ensures that the mutex is always properly released, even if an exception is thrown or the function returns early.
// Lock guards are typically used to protect shared resources from concurrent access by multiple threads.
// They are often used in conjunction with critical sections of code that need to be executed atomically.
// By using a lock guard, you can ensure that only one thread at a time can access the shared resource, preventing
// lock_guard cannot be unlocked manually.

std::mutex mtx;
int buffer = 0;
void task(const char* thread, int count)
{
    mtx.lock();
    for(int i = 0; i < count; ++i)
    {
        buffer += 1;
        std::cout << "Thread " << thread << " is executing iteration " << i << "\n";
    }
    mtx.unlock();
}

void task_guard(const char* thread, int count)
{
    std::lock_guard<std::mutex> lock(mtx); // Automatically locks the mutex
    for(int i = 0; i < count; ++i)
    {
        buffer += 1;
        std::cout << "Thread " << thread << " is executing iteration " << i << "\n";
    }
} // Automatically unlocks the mutex when going out of scope
int main()
{
    std::thread t1(task_guard, "A", 5);
    std::thread t2(task_guard, "B", 5);
    t1.join();
    t2.join();
    std::cout << "Final buffer value: " << buffer << "\n";
    return 0;
}