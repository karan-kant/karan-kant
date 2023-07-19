#include <stdio.h>
#include <stdlib.h>
#include "BT.h"

int main()
{
    int choice, val;
    tnode *root = NULL;
    int count = 0;
    while(1)
    {
        printf("Enter 1 to insert, 2 to search, 3 to display, 4 to delete and 5 to exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enter the value\n");
                scanf("%d", &val);
                root = insert(root, talloc(val));
                break;
            }
            case 2:
            {
                printf("Enter the value\n");
                scanf("%d", &val);
                search(root, val);
                break;
            }
            case 3:
            {
                display_in(root);
                break;
            }
            case 4:
            {
                printf("Enter the value\n");
                scanf("%d", &val);
                root = delete_no(root, val);
                break;
            }
            case 5:
            {
                return 0;
            }
            default:
            {
                printf("Invalid input\n");
            }
        }
    }
}