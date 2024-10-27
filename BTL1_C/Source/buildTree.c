#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <../Header/buildTree.h>

// tim diem giua
CenterPoint *centerPoint(Node *head)
{
    int length = 0;
    Node *node = head;
    while (node != NULL)
    {
        node = node->next;
        length++;
    }

    return buildTree(head, 0, length - 1);
}

// tim diem giua phia ben trai va ben phai su dung de quy
CenterPoint *buildTree(Node *head, int start, int end)
{
    if (head == NULL || start > end)
    {
        return NULL;
    }

    int mid = (start + end) / 2;
    Node *node = head;
    for (int i = start; i < mid; i++)
    {
        if (node->next == NULL)
        {
            break;
        }
        node = node->next;
    }

    CenterPoint *root = (CenterPoint *)malloc(sizeof(CenterPoint));
    root->inFo.name = node->inFo.name;
    root->inFo.age = node->inFo.age;
    root->inFo.address = node->inFo.address;
    root->inFo.phNB = node->inFo.phNB;
    root->left = buildTree(head, start, mid - 1);
    root->right = buildTree(node->next, mid + 1, end);

    return root;
}