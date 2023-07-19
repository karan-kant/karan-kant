/* Write a program to search for an element in the circular linked list by specifying the position and
the item. */

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

int searchByPosition(struct Node* head, int position) {
    if (head == NULL) {
        return -1;  // List is empty
    }

    struct Node* current = head;
    int count = 1;

    do {
        if (count == position) {
            return current->data;
        }
        current = current->next;
        count++;
    } while (current != head);

    return -1;  // Position not found
}

int searchByItem(struct Node* head, int item) {
    if (head == NULL) {
        return -1;  // List is empty
    }

    struct Node* current = head;
    int position = 1;

    do {
        if (current->data == item) {
            return position;
        }
        current = current->next;
        position++;
    } while (current != head);

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