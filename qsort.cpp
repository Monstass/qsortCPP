/* Decsription:
 1. Choosing a pivot.
 2. Split the array into 3 parts.
 *Create variables low and high - indices, respectively, of the beginning and 
 end of the considered subarray.
 *Increase low until the low-th element is less than the pivot.
 *Decrease high until the high-th element is larger than the pivot.
 * Swap the low-th and high-th elements, increment low and decrement high.
 *If low becomes larger than high, then we interrupt the cycle.
 3. Repeat recursively until we reach an array of 1 element.
*/


#include <algorithm>
#include "qsort.h"

void qsort(int* array, int start, int end){
    int low = start;
    int high = end;
    int pivot = array[(low + high) / 2];

    while (low <= high){
        while (array[low] < pivot){
            ++low;
        }
        while (array[high] > pivot){
            --high;
        }
        if (low <= high){
            std::swap(array[low], array[high]);
            ++low;
            --high;
        }
    }

    if (low < end){
        qsort(array, low, end);
    }
    if (high > start){
        qsort(array, start, high);
    }
}