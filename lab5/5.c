/* Write a program to search for an element in the singly linked list by specifying the position and the
item. */

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
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int searchByPosition(struct Node* head, int position) {
    struct Node* current = head;
    int count = 1;

    while (current != NULL) {
        if (count == position) {
            return current->data;
        }
        current = current->next;
        count++;
    }

    return -1;  // Position not found
}

int searchByItem(struct Node* head, int item) {
    struct Node* current = head;
    int position = 1;

    while (current != NULL) {
        if (current->data == item) {
            return position;
        }
        current = current->next;
        position++;
    }

    return -1;  // Item not found
}

int main() {
    struct Node* head = NULL;
    int choice, data, position, item;

    while (1) {
        printf("1. Insert element\n");
        printf("2. Search by position\n");
        printf("3. Search by item\n");
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
                printf("Enter the position to search: ");
                scanf("%d", &position);
                data = searchByPosition(head, position);
                if (data != -1) {
                    printf("Element at position %d: %d\n", position, data);
                } else {
                    printf("Position not found\n");
                }
                break;
            case 3:
                printf("Enter the item to search: ");
                scanf("%d", &item);
                position = searchByItem(head, item);
                if (position != -1) {
                    printf("Item %d found at position: %d\n", item, position);
                } else {
                    printf("Item not found\n");
                }
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