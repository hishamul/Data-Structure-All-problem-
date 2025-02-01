#include <stdio.h>

int main(){
    int arr[10],size,i;
printf("Enter the size of array:");
scanf("%d",&size);
printf("enter the element of the array : ");
for(i=0;i<size;i++){

    scanf("%d",&arr[i]);
}
printf("Array is : ");
for ( i = 0; i < size; i++)
{
    printf("%d \n",arr[i]);
}

    return 0;

}