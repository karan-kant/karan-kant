#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the doubly linked list
void insert(struct Node** head, int data) {
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

// Function to swap the data of two nodes
void swapData(struct Node* node1, struct Node* node2) {
    int temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}

// Function to sort the doubly linked list in ascending order
void sortAscending(struct Node* head) {
    struct Node* current;
    struct Node* index;

    if (head == NULL) {
        return;
    }

    for (current = head; current->next != NULL; current = current->next) {
        for (index = current->next; index != NULL; index = index->next) {
            if (current->data > index->data) {
                swapData(current, index);
            }
        }
    }
}

// Function to sort the doubly linked list in descending order
void sortDescending(struct Node* head) {
    struct Node* current;
    struct Node* index;

    if (head == NULL) {
        return;
    }

    for (current = head; current->next != NULL; current = current->next) {
        for (index = current->next; index != NULL; index = index->next) {
            if (current->data < index->data) {
                swapData(current, index);
            }
        }
    }
}

// Function to print the doubly linked list
void printLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, data;

    printf("Enter the number of elements in the doubly linked list: ");
    scanf("%d", &n);

    printf("Enter the elements of the doubly linked list: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insert(&head, data);
    }

    printf("Original doubly linked list: ");
    printLinkedList(head);

    // Sort the doubly linked list in ascending order
    sortAscending(head);
    printf("Doubly linked list in ascending order: ");
    printLinkedList(head);

    // Sort the doubly linked list in descending order
    sortDescending(head);
    printf("Doubly linked list in descending order: ");
    printLinkedList(head);

    return 0;
}
