#include<stdio.h>
#include<stdbool.h>

void bubble_sort(int arr[], int length){
    bool swapped;
    int i = 0;
    do{
        swapped = false;
        for (int j = 0; j < length - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        i++;
        // After each pass, the largest element is at the end of the array
        // So we can reduce the length of the array to be sorted
        // If no two elements were swapped in the inner loop, then break
    }while(swapped);   
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int length = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, length);
    printf("Sorted array: \n");
    for (int i = 0; i < length; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}