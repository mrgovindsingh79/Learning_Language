#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
//  recursive_mutex
// A recursive mutex is a synchronization primitive that can be locked multiple times by the same thread without causing a deadlock.
// This is useful in scenarios where a function that locks a mutex calls another function that also locks the same mutex.
// The mutex keeps track of the number of times it has been locked by the same thread, and requires an equal number of unlocks to release the mutex.
// If a thread tries to lock a recursive mutex that it already owns, the lock count is incremented, and the thread can continue executing.
// When the thread unlocks the mutex, the lock count is decremented. The mutex is only released when the lock count reaches zero.
// If a different thread tries to lock the mutex while it is already owned by another thread, it will block until the mutex is released.
// Recursive mutexes can be useful in certain scenarios, but they can also lead to performance issues and increased complexity in code.
// Therefore, they should be used judiciously and only when necessary.
//This applicable for loops also.
std::recursive_mutex mtx;
int buffer = 0;
void AddAmount(char c, int i)
{
    if(i < 0) return;
    mtx.lock();
    buffer += 1;
    std::cout << "Thread " << c << " added " << i << ", total buffer: " << buffer << "\n";
    AddAmount(c,i - 1);
    mtx.unlock();
}
int main()
{
    std::thread t1(AddAmount,'0', 10);
    std::thread t2(AddAmount,'1', 10);
    t1.join();
    t2.join();
    return 0;
}