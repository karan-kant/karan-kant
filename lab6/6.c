/* Write a C program to reverse first N elements of the linked list. */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

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

struct Node* reverseFirstN(struct Node* head, int N) {
    struct Node* prevNode = NULL;
    struct Node* current = head;
    struct Node* nextNode = NULL;

    int count = 0;
    while (current != NULL && count < N) {
        nextNode = current->next;
        current->next = prevNode;
        prevNode = current;
        current = nextNode;
        count++;
    }

    head->next = current;
    return prevNode;
}

void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

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
    int N;

    printf("Enter the number of elements: ");
    scanf("%d", &N);

    printf("Enter the elements of the linked list: ");
    for (int i = 0; i < N; i++) {
        int data;
        scanf("%d", &data);
        insertNode(&head, data);
    }

    printf("Original Linked List: ");
    displayList(head);

    int numToReverse;
    printf("Enter the number of elements to reverse: ");
    scanf("%d", &numToReverse);

    if (numToReverse > N) {
        printf("Invalid input! Number of elements to reverse exceeds the size of the linked list.\n");
        freeList(head);
        return 0;
    }

    head = reverseFirstN(head, numToReverse);

    printf("Modified Linked List (after reversing first %d elements): ", numToReverse);
    displayList(head);

    freeList(head);

    return 0;
}