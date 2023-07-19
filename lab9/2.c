#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a node in the phonebook BST
typedef struct PhonebookEntry {
    char name[50];
    char phoneNumber[15];
    struct PhonebookEntry* left;
    struct PhonebookEntry* right;
} PhonebookEntry;

// Function to create a new phonebook entry
PhonebookEntry* createEntry(const char* name, const char* phoneNumber) {
    PhonebookEntry* newEntry = (PhonebookEntry*)malloc(sizeof(PhonebookEntry));
    if (newEntry == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(newEntry->name, name);
    strcpy(newEntry->phoneNumber, phoneNumber);
    newEntry->left = NULL;
    newEntry->right = NULL;
    return newEntry;
}

// Function to insert a new entry in the phonebook BST
PhonebookEntry* insertEntry(PhonebookEntry* root, const char* name, const char* phoneNumber) {
    if (root == NULL) {
        return createEntry(name, phoneNumber);
    }

    if (strcmp(name, root->name) < 0) {
        root->left = insertEntry(root->left, name, phoneNumber);
    } else if (strcmp(name, root->name) > 0) {
        root->right = insertEntry(root->right, name, phoneNumber);
    }

    return root;
}

// Function to search for a contact by name in the phonebook BST
PhonebookEntry* searchContact(PhonebookEntry* root, const char* name) {
    if (root == NULL || strcmp(root->name, name) == 0) {
        return root;
    }

    if (strcmp(name, root->name) < 0) {
        return searchContact(root->left, name);
    } else {
        return searchContact(root->right, name);
    }
}

// Function for in-order traversal of the phonebook BST
void inorderTraversal(PhonebookEntry* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("Name: %s, Phone Number: %s\n", root->name, root->phoneNumber);
        inorderTraversal(root->right);
    }
}

int main() {
    PhonebookEntry* phonebook = NULL;
    char name[50];
    char phoneNumber[15];

    // Inserting entries into the phonebook
    phonebook = insertEntry(phonebook, "Bhanodhay", "1234567890");
    phonebook = insertEntry(phonebook, "Chavala", "9876543210");
    phonebook = insertEntry(phonebook, "Rao", "5555555555");

    printf("Phonebook entries (in-order):\n");
    inorderTraversal(phonebook);

    // Searching for a contact
    printf("\nEnter the name to search: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove trailing newline character

    PhonebookEntry* contact = searchContact(phonebook, name);
    if (contact != NULL) {
        printf("Contact found!\n");
        printf("Name: %s, Phone Number: %s\n", contact->name, contact->phoneNumber);
    } else {
        printf("Contact not found.\n");
    }

    return 0;
}
