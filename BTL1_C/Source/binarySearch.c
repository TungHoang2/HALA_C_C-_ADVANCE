#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <../Header/binarySearch.h>

CenterPoint *binarySearch(CenterPoint *root, char name[20])
{
    // static int loop = 0;
    // loop++;
    // printf("so lan lap: %d\n", loop);
    
    if (root == NULL)
    {
        return NULL;
    }

    if (!strcmp(root->inFo.name, name))
    {
        return root;
    }

    if (strcmp(name,root->inFo.name)<0)
    {
        return binarySearch(root->left, name);
    }
    else
    {
        return binarySearch(root->right, name);
    }
}

void print_list(Node *head)
{

    while (head != NULL)
    {
        printf("%s\n", head->inFo.name);
        printf("%s\n", head->inFo.age);
        printf("%s\n", head->inFo.address);
        printf("%s\n", head->inFo.phNB);
        head = head->next;
    }
    printf("\n");
}
