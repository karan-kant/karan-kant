/* Write a C program to find the maximum and minimum elements in a doubly linked list. */

#include <stdio.h>
#include <stdlib.h>

// Doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the doubly linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Function to find the maximum and minimum elements in the doubly linked list
void findMaxMin(struct Node* head, int* max, int* min) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    *max = head->data;
    *min = head->data;
    struct Node* current = head->next;

    while (current != NULL) {
        if (current->data > *max) {
            *max = current->data;
        }

        if (current->data < *min) {
            *min = current->data;
        }

        current = current->next;
    }
}

// Function to free the memory allocated for the doubly linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int choice, data;

    printf("Enter the elements of the doubly linked list (Enter -1 to stop):\n");
    while (1) {
        printf("Enter element: ");
        scanf("%d", &data);
        if (data == -1) {
            break;
        }
        insertEnd(&head, data);
    }

    int max, min;
    findMaxMin(head, &max, &min);
    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);

    freeList(head);
    return 0;
}