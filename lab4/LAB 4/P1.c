
#include <stdio.h>
#include <stdlib.h>

typedef struct book{
    char title[25];
    char autho[25];
    int year;
}bookst;

int main()
{
    printf("Enter the Details of the book\n");
    bookst *ptr;
    ptr = (bookst*)malloc(sizeof(bookst));
    printf("Enter the Title of the Book\t");
    scanf("%s", ptr->title);
    printf("Enter the Author of the Book\t");
    scanf("%s", ptr->autho);
    printf("Enter the Year of Publishing\t");
    scanf("%d", &ptr->year);

    printf("\nPrinting the details..........\n\n");
    printf("Title: %s\nAuthor: %s\nYear: %d\n", ptr->title, ptr->autho, ptr->year);
    free(ptr);
    return 0;
}
