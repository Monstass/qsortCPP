#include <iostream>
#include <random> 
#include <ctime>
#include "qsort.h"

using std::cout;

int main(){
    const int N = 10;           // N - size of array (10)
    int* array = new int[N];

    std::mt19937 mt(time(NULL)); // initializing the Mersenne twister
    std::uniform_int_distribution<> dist(0, 100);

    // pushing random numbers in array
    for (auto i = 0; i < N; ++i){
        array[i] = dist(mt);
        cout << array[i] << "\t";
    }

    qsort(array, 0, N - 1); // calling for sorting (N - 1 is important)

    // printing sorted array
    cout << "\n";
    for (auto i = 0; i < N; ++i){
        cout << array[i] << "\t";
    }

    return 0;
}