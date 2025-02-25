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
struct node* add_at_end(struct node *ptr,int data){
struct node *temp=malloc (sizeof(struct node));
temp->data=data;
temp->link=NULL;
ptr->link=temp;
return temp;
}
int main(){
    struct node *head=malloc(sizeof(struct node));
    head->data=34;
    head->link=NULL;
    struct node *ptr=head;
   
    ptr=add_at_end(ptr,77);
    ptr=add_at_end(ptr,5);
    ptr=add_at_end(ptr,7);
    ptr=add_at_end(ptr,777);
    ptr=head; 
    print_data(head);
    while (ptr!=NULL)
    {
  
    printf("%d ",ptr->data);
    ptr=ptr->link;
    }
    
    return 0;
}