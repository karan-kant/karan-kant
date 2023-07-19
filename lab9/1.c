#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with the given key
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the binary search tree
struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }

    return root;
}

// Function to search for a key in the binary search tree
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// Function to find the minimum key in a binary search tree
struct Node* findMin(struct Node* root) {
    if (root == NULL) {
        return NULL;
    } else if (root->left == NULL) {
        return root;
    } else {
        return findMin(root->left);
    }
}

// Function to delete a key from the binary search tree
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Case 1: No child or only one child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 2: Two children
        struct Node* minValueNode = findMin(root->right);
        root->data = minValueNode->data;
        root->right = deleteNode(root->right, minValueNode->data);
    }

    return root;
}

// Function for in-order traversal of the binary search tree
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to display the menu
void displayMenu() {
    printf("\n------ Binary Search Tree Operations ------\n");
    printf("1. Insert a key\n");
    printf("2. Search for a key\n");
    printf("3. Display in-order traversal\n");
    printf("4. Delete a key\n");
    printf("5. Exit\n");
}

int main() {
    struct Node* root = NULL;
    int choice, key;
    struct Node* result;

    do {
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                printf("Key inserted successfully.\n");
                break;
            case 2:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                result = search(root, key);
                if (result == NULL) {
                    printf("Key not found.\n");
                } else {
                    printf("Key found.\n");
                }
                break;
            case 3:
                printf("In-order traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                printf("Key deleted successfully.\n");
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
