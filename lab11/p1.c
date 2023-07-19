#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform selection sort
void selectionSort(int arr[], int n) {
    int i, j, minIndex;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;

        // Find the minimum element in the unsorted part of the array
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element
        swap(&arr[i], &arr[minIndex]);
    }
}

// Function to print the array elements
void display(int arr[], int n) {
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
    int arr[100];
    printf("Enter the elements\t");
    for(int i = 0; i < n; i++){
        int k;
        scanf("%d", &k);
        arr[i] = k;
    }

    printf("Original array: ");
    display(arr, n);

    selectionSort(arr, n);

    printf("Sorted array: ");
    display(arr, n);

    return 0;
}