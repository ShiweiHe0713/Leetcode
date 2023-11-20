// C++ program to sort an array
// using quick sort algorithm
/*
Time complexity: 
Space complexity: 
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

int partitioning(int arr[], int low, int high) {
    if(low >= high) return low;
    int pivot = arr[low];

    while(low < high) {
        while(high > low && arr[high] >= pivot) {
            high--;
        }
        std::swap(arr[high], arr[low]);
        while(low < high && arr[low] <= pivot) {
            low++;
        }
        std::swap(arr[high], arr[low]);
    }
    pivot = arr[low];
    int* a = &low;
    return *a;
}

void quick_sort(int arr[], int low, int high) {
    if(low >= high) return;
    int pi = partitioning(arr, low, high);
    quick_sort(arr, low, pi - 1);
    quick_sort(arr, pi + 1, high);
}