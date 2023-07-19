
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
