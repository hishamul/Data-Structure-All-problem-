#include <stdio.h>
void bubbleSort(int a[], int n)
{
    for (int outer = n - 1; outer > 0; outer--)
    {
        for (int inner = 0; inner < outer; inner++)
        {
            if (a[inner] > a[inner + 1])
            {

                int temp = a[inner];
                a[inner] = a[inner + 1];
                a[inner + 1] = temp;
            }
        }
    }
}
int main()
{
    int n;
    printf("Enter your array size:\n");

    scanf("%d", &n);
    printf("Enter your array :");
    int a[100];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    bubbleSort(a, n);

    for (int i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }

    return 0;
}