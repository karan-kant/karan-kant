#include <stdio.h>
#include <stdlib.h>

// Function to merge two subarrays
void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0;

    // Compare and merge elements from left and right subarrays
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of left subarray, if any
    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // Copy remaining elements of right subarray, if any
    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// Function to perform merge sort
void mergeSort(int arr[], int size) {
    if (size < 2) {
        return;
    }

    int mid = size / 2;
    int* left = (int*)malloc(mid * sizeof(int));
    int* right = (int*)malloc((size - mid) * sizeof(int));

    // Divide the array into two subarrays
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }

    // Recursively sort the subarrays
    mergeSort(left, mid);
    mergeSort(right, size - mid);

    // Merge the sorted subarrays
    merge(arr, left, mid, right, size - mid);

    free(left);
    free(right);
}

// Function to print the array elements
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements:\t");
    scanf("%d", &n);
    int arr[100];
    printf("Enter the elements\t");
    for(int i = 0; i < n; i++){
        int k;
        scanf("%d", &k);
        arr[i] = k;
    }

    printf("Original array: ");
    printArray(arr, n);

    mergeSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}