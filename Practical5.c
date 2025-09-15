#include <stdio.h>
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high]; // Choosing the last element as pivot
        int i = (low - 1); // Index of smaller element
        
        for (int j = low; j < high; j++) {
            // If current element is smaller than or equal to pivot
            if (arr[j] <= pivot) {
                i++; // Increment index of smaller element
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        // Swap the pivot element with the element at index i+1
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        
        int pi = i + 1; // Partitioning index
        
        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    quickSort(arr, 0, size - 1);
    
    printf("Sorted array: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}