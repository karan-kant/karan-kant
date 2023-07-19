
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


void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);

    if (*top == NULL) {
        *top = newNode;
    } else {
        newNode->next = *top;
        (*top)->prev = newNode;
        *top = newNode;
    }
}


int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }

    struct Node* temp = *top;
    int data = temp->data;

    *top = (*top)->next;

    if (*top != NULL) {
        (*top)->prev = NULL;
    }

    free(temp);
    return data;
}


void displayStack(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements: ");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}


void freeStack(struct Node* top) {
    struct Node* current = top;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Node* top = NULL;
    int choice, data;

    while (1) {
        printf("Stack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &data);
                push(&top, data);
                break;
            case 2:
                data = pop(&top);
                if (data != -1) {
                    printf("Popped element: %d\n", data);
                }
                break;
            case 3:
                displayStack(top);
                break;
            case 4:
                freeStack(top);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}
