/* Write a program to search for an element using the linear search approach. The program should be
able to allocate the memory for the required number of elements dynamically when the program is
under execution. Use the suitable dynamic memory allocation functions. */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter the Number of Elements\t");
    int n;
    scanf("%d", &n);

    int *ptr;
    ptr = (int*)malloc(n*sizeof(int));
    printf("Enter the Numbers\n");
    for(int i = 0; i < n; i++)
    {
        printf("Enter %d:\t", i + 1);
        scanf("%d", &ptr[i]);
    }
    printf("Enter the Number to be Found\t");
    int ki, check = 0;
    scanf("%d", &ki);

    for(int i = 0; i < n; i++)
    {
        if(ptr[i] == ki){
            printf("%d found at %d location \n", ptr[i], i + 1);
            check = 1;
            break;
        }
        else
            continue;
    }
    if(check == 0)
        printf("%d not found in the array\n", ki);
    free(ptr);
    return 0;
}