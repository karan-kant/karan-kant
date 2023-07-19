/* Write a program that dynamically allocates memory for a structure representing a book. The
structure should have members for the title, author, and publication year. Prompt the user to enter
the number of books.
The program should be able to read the information about the specified number of books and print
the information for a book and display it before freeing the allocated memory. */

#include <stdio.h>
#include <stdlib.h>

typedef struct book{
    char title[25];
    char autho[25];
    int year;
}bookst;

int main()
{
    printf("Enter the Number of Books\t");
    int n; 
    scanf("%d", &n);

    bookst *ptr;
    ptr = (bookst*)malloc(n*sizeof(bookst));
    printf("Enter the details\n\n");

    for(int i = 0; i < n; i++)
    {
        printf("Enter the Title of the Book\t");
        scanf("%s", ptr[i].title);
        printf("Enter the Author of the Book\t");
        scanf("%s", ptr[i].autho);
        printf("Enter the Year of Publishing\t");
        scanf("%d", &ptr[i].year);
        printf("\n");
    }

    printf("\nPrinting the details..........\n\n");

    for(int i = 0; i < n; i++)
        printf("Title: %s\nAuthor: %s\nYear: %d\n\n", ptr[i].title, ptr[i].autho, ptr[i].year);
    free(ptr);
    return 0;
}