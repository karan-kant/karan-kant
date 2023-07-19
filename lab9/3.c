#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a student node in the BST
typedef struct Student {
    char name[50];
    int grade;
    struct Student* left;
    struct Student* right;
} Student;

// Function to create a new student node
Student* createStudent(const char* name, int grade) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (newStudent == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(newStudent->name, name);
    newStudent->grade = grade;
    newStudent->left = NULL;
    newStudent->right = NULL;
    return newStudent;
}

// Function to insert a new student into the BST
Student* insertStudent(Student* root, const char* name, int grade) {
    if (root == NULL) {
        return createStudent(name, grade);
    }

    if (grade < root->grade) {
        root->left = insertStudent(root->left, name, grade);
    } else if (grade > root->grade) {
        root->right = insertStudent(root->right, name, grade);
    }

    return root;
}

// Function to search for a student by name in the BST
Student* searchStudent(Student* root, const char* name) {
    if (root == NULL || strcmp(root->name, name) == 0) {
        return root;
    }

    if (strcmp(name, root->name) < 0) {
        return searchStudent(root->left, name);
    } else {
        return searchStudent(root->right, name);
    }
}

// Function for in-order traversal of the student BST
void inorderTraversal(Student* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("Name: %s, Grade: %d\n", root->name, root->grade);
        inorderTraversal(root->right);
    }
}

// Function to find the student with the highest grade in the BST
Student* findHighestGradeStudent(Student* root) {
    if (root == NULL) {
        return NULL;
    }

    while (root->right != NULL) {
        root = root->right;
    }

    return root;
}

// Function to find the student with the lowest grade in the BST
Student* findLowestGradeStudent(Student* root) {
    if (root == NULL) {
        return NULL;
    }

    while (root->left != NULL) {
        root = root->left;
    }

    return root;
}

int main() {
    Student* studentBST = NULL;
    char name[50];
    int grade;

    // Inserting student grades into the BST
    studentBST = insertStudent(studentBST, "Bhanodhay", 80);
    studentBST = insertStudent(studentBST, "Rao", 90);
    studentBST = insertStudent(studentBST, "Chavala", 70);

    printf("Student details (in-order):\n");
    inorderTraversal(studentBST);

    // Searching for a student
    printf("\nEnter the name of the student to search: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove trailing newline character

    Student* foundStudent = searchStudent(studentBST, name);
    if (foundStudent != NULL) {
        printf("Student found!\n");
        printf("Name: %s, Grade: %d\n", foundStudent->name, foundStudent->grade);
    } else {
        printf("Student not found.\n");
    }

    // Finding the highest and lowest performing students
    Student* highestGradeStudent = findHighestGradeStudent(studentBST);
    Student* lowestGradeStudent = findLowestGradeStudent(studentBST);

    if (highestGradeStudent != NULL) {
        printf("Highest Performing Student: Name: %s, Grade: %d\n", highestGradeStudent->name, highestGradeStudent->grade);
    }

    if (lowestGradeStudent != NULL) {
        printf("Lowest Performing Student: Name: %s, Grade: %d\n", lowestGradeStudent->name, lowestGradeStudent->grade);
    }

    return 0;
}
