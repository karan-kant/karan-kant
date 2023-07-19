
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


void enqueue(struct Node** front, struct Node** rear, int data) {
    struct Node* newNode = createNode(data);

    if (*rear == NULL) {
        *front = *rear = newNode;
    } else {
        newNode->prev = *rear;
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

int dequeue(struct Node** front, struct Node** rear) {
    if (*front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }

    struct Node* temp = *front;
    int data = temp->data;

    *front = (*front)->next;

    if (*front != NULL) {
        (*front)->prev = NULL;
    } else {
        *rear = NULL;
    }

    free(temp);
    return data;
}

void displayQueue(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    while (front != NULL) {
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}

void freeQueue(struct Node* front) {
    struct Node* current = front;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Node* front = NULL;
    struct Node* rear = NULL;
    int choice, data;

    while (1) {
        printf("Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &data);
                enqueue(&front, &rear, data);
                break;
            case 2:
                data = dequeue(&front, &rear);
                if (data != -1) {
                    printf("Dequeued element: %d\n", data);
                }
                break;
            case 3:
                displayQueue(front);
                break;
            case 4:
                freeQueue(front);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}
