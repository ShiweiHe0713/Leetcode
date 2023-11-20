// C++ program to sort an array
// using bucket sort algorithm
/*
Time complexity: 
Space complexity: 
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

void bucket_sort(float arr[], int n) {
    // create buckets
    std::vector<float> buckets[n];
    // split the array into buckets
    for(int i = 0; i < n; i++) {
        int bucket_idx = n * arr[i];
        buckets[bucket_idx].push_back(arr[i]);
    }

    // sort every bucket
    for(int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // merge all the bucket
    int base = 0;
    for(int i = 0; i < n; i++) {;
        for(int j = 0; j < buckets[i].size(); j++) {
            arr[base++] = buckets[i][j];
        }
    }
}

void bucket_sort(int arr[], int n) {
    // To be implemented
}