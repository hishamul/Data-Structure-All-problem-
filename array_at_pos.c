#include<stdio.h>
int main(){
    int a[50],size,i,pos,num;
    printf("enter the array size: ");
    scanf("%d",&size);
    printf("enter the array element: ");
    for ( i = 0; i <size; i++)
    {
    scanf("%d",&a[i]);
    }
    printf("enter position you want to insert");
    scanf("%d",&pos);
   
    printf("enter data you want to insert");
    scanf("%d",&num);
   
  
    for ( i = size-1; i >pos-1; i--)
    {
        a[i+1]=a[i];
    }
    a[pos-1]=num;
     size++;


    for ( i = 0; i <size; i++)
    {
        printf("%d ",a[i]);
    
    }
    
   
    
    return 0;

}