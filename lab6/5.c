/* Write a C program to check whether a given string is a palindrome or not using the linked lists. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Node {
    char data;
    struct Node* next;
};

void insertNode(struct Node** head, char data) {
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

bool isPalindrome(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    struct Node* slowPtr = head;
    struct Node* fastPtr = head;

    // Move fast pointer to the end and slow pointer to the middle of the list
    while (fastPtr->next != NULL && fastPtr->next->next != NULL) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    // Reverse the second half of the list
    struct Node* prevNode = NULL;
    struct Node* currNode = slowPtr->next;
    while (currNode != NULL) {
        struct Node* nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }

    // Compare the first half and the reversed second half of the list
    struct Node* left = head;
    struct Node* right = prevNode;
    while (right != NULL) {
        if (left->data != right->data) {
            return false;
        }
        left = left->next;
        right = right->next;
    }

    return true;
}

void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%c ", current->data);
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
    char input[100];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    int i;
    for (i = 0; i < strlen(input); i++) {
        insertNode(&head, input[i]);
    }

    if (isPalindrome(head)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    freeList(head);

    return 0;
}