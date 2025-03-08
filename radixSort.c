#include <stdio.h>

#define RANGE 10  // The counting array size should be 10 for digit sorting

int getMax(int A[], int n) {
    int i, max = A[0];  // Initialize max as the first element
    for (i = 1; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    return max;
}

void countingSort(int A[], int n, int pos) {
    int count[RANGE] = {0};  // Counting array for digits 0-9
    int output[n];  // Output array

    // Step 1: Count occurrences of each digit at position pos
    for (int i = 0; i < n; i++) {
        count[(A[i] / pos) % 10]++;
    }

    // Step 2: Compute cumulative sum in count array
    for (int i = 1; i < RANGE; i++) {
        count[i] += count[i - 1];
    }

    // Step 3: Place elements in correct position in output array
    for (int i = n - 1; i >= 0; i--) {
        output[--count[(A[i] / pos) % 10]] = A[i];
    }

    // Step 4: Copy sorted elements back to original array
    for (int i = 0; i < n; i++) {
        A[i] = output[i];
    }
}

void radixSort(int A[], int n) {
    int m = getMax(A, n);
    for (int pos = 1; m / pos > 0; pos *= 10) {
        countingSort(A, n, pos);
    }
}

int main() {
    int A[] = {170, 45, 75, 90, 802, 24, 2, 66};  // Example input array
    int n = sizeof(A) / sizeof(A[0]); // Calculate size of the array

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    radixSort(A, n); // Sorting function call

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}
