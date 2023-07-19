
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* current = *head;
        while (current->next != *head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = *head;
    }
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("Circular Linked List is empty\n");
        return;
    }

    struct Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortAscending(struct Node* head) {
    if (head == NULL) {
        return;
    }

    struct Node* current = head;
    struct Node* index = NULL;
    int temp;

    do {
        index = current->next;
        while (index != head) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    } while (current != head);
}

void sortDescending(struct Node* head) {
    if (head == NULL) {
        return;
    }

    struct Node* current = head;
    struct Node* index = NULL;
    int temp;

    do {
        index = current->next;
        while (index != head) {
            if (current->data < index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    } while (current != head);
}

int main() {
    struct Node* head = NULL;
    int choice, data;

    while (1) {
        printf("1. Insert element\n");
        printf("2. Sort in ascending order\n");
        printf("3. Sort in descending order\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &data);
                insert(&head, data);
                break;
            case 2:
                sortAscending(head);
                printf("List sorted in ascending order.\n");
                break;
            case 3:
                sortDescending(head);
                printf("List sorted in descending order.\n");
                break;
            case 4:
                display(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
