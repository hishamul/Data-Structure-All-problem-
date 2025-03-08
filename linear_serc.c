#include <stdio.h>

void linear_s(int A[], int item, int n) {
    int found = 0; // Found flag

    for (int i = 0; i < n; i++) {
        if (A[i] == item) {
            printf("Data found at index: %d\n", i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Not found\n");
    }
}

int main() {
    int n, item; 
    printf("Enter your array length: ");
    scanf("%d", &n);

    int A[n]; // Declare array after knowing its size

    printf("Enter your array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    printf("Enter the item to search: ");
    scanf("%d", &item);

    linear_s(A, item, n);

    return 0;
}
