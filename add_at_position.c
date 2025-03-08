#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node* add_at_end(struct node *ptr, int data) {
    struct node *temp = malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->data = data;
    temp->link = NULL;
    ptr->link = temp;
    return temp;
}

void add_at_position(struct node **head, int data, int pos) {
    struct node *ptr = *head;
    struct node *ptr2 = malloc(sizeof(struct node));
    
    if (ptr2 == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    ptr2->data = data;
    ptr2->link = NULL;

    // If inserting at head (position 1)
    if (pos == 1) {
        ptr2->link = *head;
        *head = ptr2;
        return;
    }

    pos--; // Adjusting for 0-based indexing
    while (pos != 1 && ptr->link != NULL) {
        ptr = ptr->link;
        pos--;
    }

    if (pos != 1) { 
        printf("Position out of range\n");
        free(ptr2);
        return;
    }

    ptr2->link = ptr->link;
    ptr->link = ptr2;
}

void print_list(struct node *head) {
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL\n");
}

int main() {
    struct node *head = malloc(sizeof(struct node));
    if (head == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    head->data = 10;
    head->link = NULL;
    struct node *ptr = head;

    ptr = add_at_end(ptr, 77);
    ptr = add_at_end(ptr, 5);
    ptr = add_at_end(ptr, 7);
    ptr = add_at_end(ptr, 777);

    int data = 80, position = 3;
    add_at_position(&head, data, position);

    print_list(head);
    
    return 0;
}
