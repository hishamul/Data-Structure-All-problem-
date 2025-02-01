#include <stdio.h>

int main(){
    int arr[20],size,pos,num,i;
    printf("Enter the array size:");
    scanf("%d",&size);
    printf("Enter the Position:");
    scanf("%d",&pos);
    printf("Enter the Number");
    scanf("%d",&num);
    printf("Enter the array element ");
    for ( i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    if (pos>size)
    {
    printf("Overflow array");
    }
    for ( i = size-1; i >pos-1; i--)
    {
       arr[i+1]=arr[i];
    }
    arr[pos-1]=num;
    size++;
    for ( i = 0; i <size; i++)
    {
            printf("%d",arr[i]);
    }
    
    return 0;
}