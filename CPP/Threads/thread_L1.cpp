#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
using namespace std;
using namespace std::chrono;
typedef unsigned long long ull;
// Function to add even numbers
void addEven(ull start, ull end, ull& evenSum) {
    evenSum = 0;
    for (ull i=0; i<end; i++) {
        if (i % 2 == 0)
            evenSum += i;
    }
}
// Function to add odd numbers
void addOdd(ull start, ull end, ull& oddSum) {
    oddSum = 0;
    for (ull i=0; i<end; i++){
        if (i % 2 != 0)
            oddSum += i;
    }
}

// Example usage
int main() {
    ull evenSum, oddSum;
    ull start = 1, end = 1000000000;
    auto start_time = high_resolution_clock::now();

    //Since we have passed by reference, thatswhy we have add ref() while passing the parameters
    thread t1(addOdd, start, end, ref(oddSum));
    thread t2(addEven, start, end, ref(evenSum));
    t1.join();
    t2.join();
    //addOdd(start, end, oddSum);
    //addEven(start, end, evenSum);
    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end_time - start_time);
    
    cout << "Time taken without threads: " << duration.count()/1000000 << " seconds"<<std::endl;
    cout << "Sum of even numbers: "<<evenSum <<endl;
    cout << "Sum of odd numbers: " << oddSum << endl;
    return 0;
}