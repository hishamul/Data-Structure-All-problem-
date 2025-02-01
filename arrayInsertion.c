#include <stdio.h>

int main(){
    int arr[20],size,pos,num,i;
    printf("Enter the array size:");
    scanf("%d",&size);
    printf("Enter the Position:");
    scanf("%d",&pos);
    printf("Enter the Number");
    scanf("%d",&num);
    if (size>arr[20])
    {
    printf("Overflow array");
    }
    
    return 0;
}