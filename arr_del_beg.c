#include <stdio.h>

int main(){
    int a[50],size,i;
    printf("enter the array size: ");
    scanf("%d",&size);
    printf("enter the array element: ");
    for ( i = 0; i <size; i++)
    {
    scanf("%d",&a[i]);
    }
for ( i = 0; i < size-1; i++)
{
a[i]=a[i+1];
}
size--;
printf("Delation array is: ");
for ( i = 0; i <size; i++)
{
    printf("%d ",a[i]);

}



    return 0;
}