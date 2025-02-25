#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void print_data(struct node *head){
if (head==NULL)
printf("Linked is empty");
struct node *ptr=NULL;
ptr=head;
while (ptr!=NULL)
{
    printf("%d ",ptr->data);
    ptr=ptr->link;
}
}
void counts_of_nodes(struct node *head){
       int count=0;
        if (head==NULL)
        printf("Linked is empty");
        struct node *ptr=NULL;
        ptr=head;
        while (ptr!=NULL)
        {
            count++;
         
            ptr=ptr->link;
        }
        printf("%d ",count);


}
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
    print_data(head);
    counts_of_nodes(head);
    return 0;
}