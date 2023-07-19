#include <stdio.h>
#include "BT.h"

int main()
{
    int n;
    printf("ENTER THE NUMBER OF VALUES TO BE INSERTED\n");
    scanf("%d", &n);

    tnode *root = NULL;
    for(int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        root = insert(root, talloc(a));
    }

    printf("INORDER\n");
    display_in(root);

    printf("POSTORDER\n");
    display_po(root);

    printf("PREORDER\n");
    display_pre(root);
}