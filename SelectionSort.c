#include<stdio.h>

void selection_sort(int arr[], int length) {
    for (int i = 0; i < length - 1; i++) {
        // Find the minimum element in unsorted array
        int min_index = i;
        for (int j = i + 1; j < length; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        // Swap the found minimum element with the first elemen if its not already in place
        if(min_index != i){
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
        }
    }
}

