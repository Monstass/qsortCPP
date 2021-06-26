#include <iostream>
#include <random> 
#include <ctime>
#include <iomanip>
#include "Qsort.h"

using std::cout;

int main(){
    const int N = 10;           // N - size of array (10)
    int* array = new int[N];
    int* array_to_reverse = new int[N];
    Sort do_sort;

    std::mt19937 mt(time(NULL)); // initializing the Mersenne twister
    std::uniform_int_distribution<> dist(0, 100);

    // pushing random numbers in array
    cout << "Array to sort: " << std::right << std::setw(10);
    for (auto i = 0; i < N; ++i){
        array[i] = dist(mt);
        cout << array[i] << std::internal << std::setw(10);
    }
    cout << "\nArray to reverse sort: ";
    for (auto i = 0; i < N; ++i){
        array_to_reverse[i] = dist(mt);
        cout << array_to_reverse[i] << std::internal << std::setw(10);;
    }
    cout << "\n---------------------------------------------------------";

    do_sort.qsort(array, 0, N - 1); // calling for sorting (N - 1 is important)
    do_sort.qsortReverse(array_to_reverse, 0, N - 1); // reverse sorting

    // printing sorted array
    cout << "\nSorted array: " << std::right << std::setw(10);;
    for (auto i = 0; i < N; ++i){
        cout << array[i] << std::internal << std::setw(10);
    }    
    // printing reverse sorted array
    cout << "\nReverse sorted array: ";
    for (auto i = 0; i < N; ++i){
        cout << array_to_reverse[i] << std::internal << std::setw(10);
    }

    delete[] array;
    delete[] array_to_reverse;

    return 0;
}