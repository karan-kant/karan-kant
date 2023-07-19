#include <stdio.h>

// Function to perform the Bubble Sort algorithm
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to perform binary search and return the index if found, or -1 if not found
int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = (high + low) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

// Function to print the array elements
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements:\t");
    scanf("%d", &n);
    int arr[100d];
    printf("Enter the elements\t");
    for(int i = 0; i < n; i++){
        int k;
        scanf("%d", &k);
        arr[i] = k;
    }


    // Sort the array in descending order using Bubble Sort
    bubbleSort(arr, n);

    printf("Sorted array in descending order: ");
    printArray(arr, n);

    int key;
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Perform binary search
    int index = binarySearch(arr, 0, n - 1, key);
    if (index != -1) {
        printf("Element %d found at index %d\n", key, index);
    } else {
        printf("Element %d not found\n", key);
    }
    //printf("Sorted Array:\t");
    //printArray(arr, n);

    return 0;
}