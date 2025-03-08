#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Entity structure
typedef struct {
    int entity_id;
    char name[100];
    int age;
    float cgpa;
} Entity;

// Array-based database operations

void append_array(Entity *database, int *size, Entity entity, int index) {
    if (index < 0 || index > *size) {
        printf("Invalid index\n");
        return;
    }

    // Shift elements to the right
    for (int i = *size; i > index; i--) {
        database[i] = database[i - 1];
    }

    // Insert the new entity
    database[index] = entity;
    (*size)++;
}

void delete_array(Entity *database, int *size, int entity_id) {
    int index = -1;
    for (int i = 0; i < *size; i++) {
        if (database[i].entity_id == entity_id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Entity not found\n");
        return;
    }

    // Shift elements to the left
    for (int i = index; i < *size - 1; i++) {
        database[i] = database[i + 1];
    }

    (*size)--;
}

int compare(const void *a, const void *b) {
    return ((Entity*)a)->entity_id - ((Entity*)b)->entity_id;
}

void sort_array(Entity *database, int size) {
    qsort(database, size, sizeof(Entity), compare);
}

Entity* search_array(Entity *database, int size, int entity_id) {
    for (int i = 0; i < size; i++) {
        if (database[i].entity_id == entity_id) {
            return &database[i];
        }
    }
    return NULL;
}

// Linked List-based database operations

typedef struct Node {
    Entity data;
    struct Node *next;
} Node;

void append_linked_list(Node **head, Entity entity) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = entity;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void delete_linked_list(Node **head, int entity_id) {
    Node *temp = *head;
    Node *prev = NULL;

    if (temp != NULL && temp->data.entity_id == entity_id) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data.entity_id != entity_id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Entity not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

Node* merge(Node *left, Node *right) {
    if (!left) return right;
    if (!right) return left;

    if (left->data.entity_id < right->data.entity_id) {
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
    }
}

Node* merge_sort(Node *head) {
    if (!head || !head->next) {
        return head;
    }

    Node *middle = head;
    Node *fast = head->next;
    while (fast && fast->next) {
        middle = middle->next;
        fast = fast->next->next;
    }

    Node *left = head;
    Node *right = middle->next;
    middle->next = NULL;

    left = merge_sort(left);
    right = merge_sort(right);

    return merge(left, right);
}

void sort_linked_list(Node **head) {
    *head = merge_sort(*head);
}

Node* search_linked_list(Node *head, int entity_id) {
    Node *temp = head;
    while (temp != NULL) {
        if (temp->data.entity_id == entity_id) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Main function to test operations on both Array and Linked List

int main() {
    Entity database[100]; // For array
    int size = 0; // For array size
    
    Node *head = NULL; // For linked list
    
    // Create sample entities
    Entity e1 = {1, "Alice", 20, 3.9};
    Entity e2 = {2, "Bob", 22, 3.5};
    Entity e3 = {3, "Charlie", 21, 3.7};

    // Array Operations
    printf("Array Operations:\n");
    append_array(database, &size, e1, 0);
    append_array(database, &size, e2, 1);
    append_array(database, &size, e3, 1);
    
    delete_array(database, &size, 2);
    
    sort_array(database, size);
    
    Entity *search_result = search_array(database, size, 1);
    if (search_result != NULL) {
        printf("Found Entity in Array: %s\n", search_result->name);
    }

    // Linked List Operations
    printf("\nLinked List Operations:\n");
    append_linked_list(&head, e1);
    append_linked_list(&head, e2);
    append_linked_list(&head, e3);
    
    delete_linked_list(&head, 2);
    
    sort_linked_list(&head);
    
    Node *search_result_ll = search_linked_list(head, 1);
    if (search_result_ll != NULL) {
        printf("Found Entity in Linked List: %s\n", search_result_ll->data.name);
    }

    return 0;
}
