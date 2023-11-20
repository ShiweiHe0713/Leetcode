#include <iostream>
#include <cstdio>

#include "algorithms_calvin.cpp"


int main() {
    float arr_float[] = { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 };
    int arr_int[] = { 897, 565, 656, 1234, 665, 3434 };
    int n = sizeof(arr_float) / sizeof(arr_float[0]);
    int n2 = sizeof(arr_int) / sizeof(arr_int[0]);

    // bucket_sort(arr_float, n);
    quick_sort(arr_int, 0, n - 1);

    std::cout << "Sorted array is \n";
    for (int i = 0; i < n; i++)
        std::cout << arr_int[i] << " ";
    return 0;
}