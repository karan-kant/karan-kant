#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node {
    int data;
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
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
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
    }
}

// Function to swap every two adjacent nodes in the linked list
void swapAdjacentNodes(struct Node* head) {
    struct Node* current = head;

    // Traverse the list and swap every two adjacent nodes
    while (current != NULL && current->next != NULL) {
        int temp = current->data;
        current->data = current->next->data;
        current->next->data = temp;
        current = current->next->next;
    }
}

// Function to print the linked list
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

    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    if (n % 2 != 0) {
        printf("Number of elements must be even.\n");
        return 0;
    }

    printf("Enter the elements of the linked list: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insert(&head, data);
    }

    printf("Original linked list: ");
    printLinkedList(head);

    swapAdjacentNodes(head);

    printf("Resultant linked list after swapping adjacent nodes: ");
    printLinkedList(head);

    return 0;
}
