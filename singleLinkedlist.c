#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};

int main(){
    struct node *head=malloc(sizeof(struct node));
    head->data=34;
    head->link=NULL;
    struct node *current=malloc(sizeof(struct node));
    current->data=65;
    current->link=NULL;
    head->link=current;
    current =malloc(sizeof(struct node));
    current->data=76;
    current->link=NULL;
    head->link->link=current;
    printf("%d",head->link->link->data);
    
    return 0;
}