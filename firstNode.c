#include <stdio.h>
#include<stdlib.h>
struct firstNode
{
    int data;
    struct firstNode *link;
   
    
};

int main(){
    struct firstNode *head=NULL;
    head=malloc(sizeof(struct firstNode));
    head->data=45;
    head->link=NULL;

    printf("%d",head->data);
    return 0;
}