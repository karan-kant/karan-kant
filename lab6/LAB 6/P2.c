
#include <stdio.h>
#include <stdlib.h>

struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
};

void insertTerm(struct Term** head, int coefficient, int exponent) {
    struct Term* newNode = (struct Term*)malloc(sizeof(struct Term));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Term* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void displayPolynomial(struct Term* head) {
    struct Term* current = head;
    while (current != NULL) {
        printf("%dx^%d ", current->coefficient, current->exponent);
        current = current->next;
        if (current != NULL) {
            printf("+ ");
        }
    }
    printf("\n");
}

int main() {
    struct Term* head = NULL;
    int coefficient, exponent, choice;

    while (1) {
        printf("1. Insert term\n");
        printf("2. Display polynomial\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter coefficient: ");
                scanf("%d", &coefficient);
                printf("Enter exponent: ");
                scanf("%d", &exponent);
                insertTerm(&head, coefficient, exponent);
                break;
            case 2:
                displayPolynomial(head);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
