#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the binary tree
struct Node {
    int key;
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
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node with the given key into the binary tree
struct Node* insert(struct Node* root, int key, int* count) {
    if (root == NULL) {
        (*count)++;
        return createNode(key);
    }

    if (*count % 2 == 0) {
        root->left = insert(root->left, key, count);
    } else {
        root->right = insert(root->right, key, count);
    }

    return root;
}

// Function to search for a key in the binary tree
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }

    struct Node* result = search(root->left, key);
    if (result == NULL) {
        result = search(root->right, key);
    }

    return result;
}

// Function to perform inorder traversal of the binary tree and display the elements
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

// Function to find the minimum value node in a given binary tree
struct Node* findMinNode(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node with the given key from the binary tree
struct Node* deleteNode(struct Node* root, int key, int* count) {
    if (root == NULL) {
        return root;
    }

    if (root->key == key) {
        (*count)--;
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* minNode = findMinNode(root->right);
        root->key = minNode->key;
        root->right = deleteNode(root->right, minNode->key, count);
    } else {
        root->left = deleteNode(root->left, key, count);
        root->right = deleteNode(root->right, key, count);
    }

    return root;
}

// Function to display the menu options
void displayMenu() {
    printf("\nBinary Tree Operations\n");
    printf("1. Insert\n");
    printf("2. Search\n");
    printf("3. Display (Inorder Traversal)\n");
    printf("4. Delete\n");
    printf("5. Exit\n");
}

int main() {
    struct Node* root = NULL;
    int choice, key;
    int count = 0;
    struct Node* result;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                root = insert(root, key, &count);
                printf("Node inserted successfully!\n");
                break;
            case 2:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                result = search(root, key);
                if (result != NULL) {
                    printf("Key %d found in the binary tree.\n", key);
                } else {
                    printf("Key %d not found in the binary tree.\n", key);
                }
                break;
            case 3:
                printf("Inorder traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key, &count);
                printf("Node deleted successfully!\n");
                break;
            case 5:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 5);

    // Freeing the allocated memory
    // Call a function to deallocate the entire tree (optional)
    // deallocateTree(root);

    return 0;
}
