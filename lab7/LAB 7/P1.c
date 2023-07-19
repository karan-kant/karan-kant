
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


void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;

    if (*head != NULL) {
        (*head)->prev = newNode;
    }

    *head = newNode;
}


void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* current = *head;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
}


void insertAfterPosition(struct Node** head, int data, int position) {
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }

    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    int count = 1;

    while (count < position - 1 && current != NULL) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        printf("Invalid position.\n");
        return;
    }

    newNode->next = current->next;
    newNode->prev = current;
    current->next = newNode;

    if (newNode->next != NULL) {
        newNode->next->prev = newNode;
    }
}


void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;

    if (*head != NULL) {
        (*head)->prev = NULL;
    }

    free(temp);
}


void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = *head;

    while (current->next != NULL) {
        current = current->next;
    }

    if (current->prev != NULL) {
        current->prev->next = NULL;
    } else {
        *head = NULL;
    }

    free(current);
}


void deleteAtPosition(struct Node** head, int position) {
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1) {
        deleteAtBeginning(head);
        return;
    }

    struct Node* current = *head;
    int count = 1;

    while (count < position && current != NULL) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        printf("Invalid position.\n");
        return;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        *head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
}


void displayForward(struct Node* head) {
    printf("Forward Order: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}


void displayReverse(struct Node* head) {
    if (head == NULL) {
        return;
    }

    struct Node* current = head;

    while (current->next != NULL) {
        current = current->next;
    }

    printf("Reverse Order: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
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
    int choice, data, position;

    while (1) {
        printf("Doubly Linked List Operations:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert after a given position\n");
        printf("4. Delete at the beginning\n");
        printf("5. Delete at the end\n");
        printf("6. Delete at a given position\n");
        printf("7. Display the list in forward order\n");
        printf("8. Display the list in reverse order\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &position);
                insertAfterPosition(&head, data, position);
                break;
            case 4:
                deleteAtBeginning(&head);
                break;
            case 5:
                deleteAtEnd(&head);
                break;
            case 6:
                printf("Enter the position: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 7:
                displayForward(head);
                break;
            case 8:
                displayReverse(head);
                break;
            case 9:
                freeList(head);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}
