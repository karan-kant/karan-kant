/* Write a C program to add two ordered polynomial expressions using the linked list. */

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

void addPolynomials(struct Term* poly1, struct Term* poly2, struct Term** result) {
    struct Term* current1 = poly1;
    struct Term* current2 = poly2;

    while (current1 != NULL && current2 != NULL) {
        if (current1->exponent > current2->exponent) {
            insertTerm(result, current1->coefficient, current1->exponent);
            current1 = current1->next;
        } else if (current1->exponent < current2->exponent) {
            insertTerm(result, current2->coefficient, current2->exponent);
            current2 = current2->next;
        } else {
            int sum = current1->coefficient + current2->coefficient;
            if (sum != 0) {
                insertTerm(result, sum, current1->exponent);
            }
            current1 = current1->next;
            current2 = current2->next;
        }
    }

    while (current1 != NULL) {
        insertTerm(result, current1->coefficient, current1->exponent);
        current1 = current1->next;
    }

    while (current2 != NULL) {
        insertTerm(result, current2->coefficient, current2->exponent);
        current2 = current2->next;
    }
}

int main() {
    struct Term* poly1 = NULL;
    struct Term* poly2 = NULL;
    struct Term* result = NULL;
    int coefficient, exponent, choice;

    while (1) {
        printf("1. Insert term into Polynomial 1\n");
        printf("2. Insert term into Polynomial 2\n");
        printf("3. Add Polynomials\n");
        printf("4. Display Polynomial 1\n");
        printf("5. Display Polynomial 2\n");
        printf("6. Display Resultant Polynomial\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter coefficient: ");
                scanf("%d", &coefficient);
                printf("Enter exponent: ");
                scanf("%d", &exponent);
                insertTerm(&poly1, coefficient, exponent);
                break;
            case 2:
                printf("Enter coefficient: ");
                scanf("%d", &coefficient);
                printf("Enter exponent: ");
                scanf("%d", &exponent);
                insertTerm(&poly2, coefficient, exponent);
                break;
            case 3:
                addPolynomials(poly1, poly2, &result);
                printf("Polynomials added.\n");
                break;
            case 4:
                printf("Polynomial 1: ");
                displayPolynomial(poly1);
                break;
            case 5:
                printf("Polynomial 2: ");
                displayPolynomial(poly2);
                break;
            case 6:
                printf("Resultant Polynomial: ");
                displayPolynomial(result);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}