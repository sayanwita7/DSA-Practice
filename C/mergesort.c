#include <stdio.h>


// Function to merge two halves of an array
void merge(int arr[], int left, int mid, int right) {
    // Calculate the sizes of two sub-arrays to be merged
    int n1 = mid - left + 1; // Length of the left sub-array
    int n2 = right - mid;    // Length of the right sub-array

    // Create temporary arrays to hold the two halves
    int L[n1], R[n2];

    // Copy the data into the temporary arrays
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i]; // Copy elements to left array
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i]; // Copy elements to right array
    }

    // Merge the temporary arrays back into the original array
    int i = 0;    // Initial index of left sub-array
    int j = 0;    // Initial index of right sub-array
    int k = left; // Initial index of merged sub-array

    // Merge the two sub-arrays into the original array
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];  // If element in left sub-array is smaller, copy it to arr
            i++;
        } else {
            arr[k] = R[j];  // If element in right sub-array is smaller, copy it to arr
            j++;
        }
        k++; // Move to the next position in the merged array
    }

    // If there are remaining elements in the left sub-array, copy them to arr
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // If there are remaining elements in the right sub-array, copy them to arr
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to divide the array into two halves and sort them
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Find the middle point
        int mid = left + (right - left) / 2;

        // Recursively divide and sort the left half
        mergeSort(arr, left, mid);

        // Recursively divide and sort the right half
        mergeSort(arr, mid + 1, right);

        // Merge the two halves
        merge(arr, left, mid, right);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to test merge sort
int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10}; // Example array to be sorted
    int arr_size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    printf("Unsorted array: \n");
    printArray(arr, arr_size); // Print the unsorted array

    mergeSort(arr, 0, arr_size - 1); // Call mergeSort to sort the array

    printf("\nSorted array: \n");
    printArray(arr, arr_size); // Print the sorted array

    return 0;
}