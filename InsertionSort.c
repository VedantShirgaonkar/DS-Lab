#include <stdio.h>

void insertion_sort(int arr[], int length) {
    for (int i = 1; i < length; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void print_array(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {9, 5, 1, 4, 3};
    int length = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    print_array(arr, length);

    insertion_sort(arr, length);

    printf("Sorted array:   ");
    print_array(arr, length);

    return 0;
}