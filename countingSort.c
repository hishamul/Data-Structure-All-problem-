#include <stdio.h>

#define RANGE 100  // Define the range for the counting sort (adjust as needed)

// Function to perform Counting Sort
void countingSort(int A[], int n) {
    int count[RANGE + 1] = {0};  // Count array
    int output[n];  // Output array

    // Step 1: Count occurrences of each element
    for (int i = 0; i < n; i++) {
        count[A[i]]++;
    }

    // Step 2: Compute cumulative sum in count array
    for (int i = 1; i <= RANGE; i++) {
        count[i] += count[i - 1];
    }

    // Step 3: Place elements in correct position in output array
    for (int i = n - 1; i >= 0; i--) {
        output[--count[A[i]]] = A[i];
    }

    // Step 4: Copy sorted elements back to original array
    for (int i = 0; i < n; i++) {
        A[i] = output[i];
    }
}

// Main function to test countingSort
int main() {
    int A[] = {4, 2, 2, 8, 3, 3, 1};  // Example input array
    int n = sizeof(A) / sizeof(A[0]); // Calculate size of the array

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    countingSort(A, n); // Sorting function call

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}

