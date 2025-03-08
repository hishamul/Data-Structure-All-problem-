#include <stdio.h>
int binary_search(int A[],int n,int data){
int l,r,mid;
l=0,r=n-1;
while (l<=r)
{
    mid=(l+r)/2;
    if (data==A[mid])
    {
        return mid;
    }
    else if (data>A[mid])
    {
        l=mid+1;
    }
    else 
    r=mid-1;
}
return -1;



}
int main(){
    int data,n;
    printf("Enter your array length:");
    scanf("%d",&n);
int A[n];
printf("Enter your array elements: ");
for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
}
printf("Enter your array data to be search: ");
scanf("%d",&data);
binary_search(A,n,data);
printf("Data is found at index %d", binary_search(A, n, data));
    return 0;
}