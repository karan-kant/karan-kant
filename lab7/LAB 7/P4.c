

#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


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
