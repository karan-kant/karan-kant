#include <stdio.h>

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    int i, key, j;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

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

    insertionSort(arr, n);

    printf("Sorted array: ");
    display(arr, n);

    return 0;
}