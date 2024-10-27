#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    struct
    {
        char *name;
        char *age;
        char *address;
        char *pNB;
    } Info;
    struct Node *next;
} Node;

void xuLyData(Node **head)
{
    FILE *file;
    char line[1024];

    file = fopen("Information.csv", "r");
    fgets(line, sizeof(line), file);
    while (fgets(line, sizeof(line), file) != NULL)
    {
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->Info.name = NULL;
        new_node->Info.age = NULL;
        new_node->Info.address = NULL;
        new_node->Info.pNB = NULL;
        new_node->next = NULL;

        char *token = strtok(line, ",");

        if (token != NULL)
        {
            new_node->Info.name = strdup(token);
        }

        token = strtok(NULL, ",");
        if (token != NULL)
        {
            new_node->Info.age = strdup(token);
        }

        token = strtok(NULL, ",");
        if (token != NULL)
        {
            new_node->Info.address = strdup(token);
        }

        token = strtok(NULL, ",");
        if (token != NULL)
        {
            new_node->Info.pNB = strdup(token);
        }

        if (*head == NULL || strcmp((*head)->Info.name, new_node->Info.name) >= 0)
        {
            new_node->next = *head;
            *head = new_node;
        }
        else
        {
            Node *current = *head;
            while (current->next != NULL && strcmp(current->next->Info.name, new_node->Info.name) < 0)
            {
                current = current->next;
            }

            new_node->next = current->next;
            current->next = new_node;
        }
    }
    fclose(file);
}

typedef struct CenterPoint
{
    struct
    {
        char *name;
        char *age;
        char *address;
        char *pNB;
    } Info;
    struct CenterPoint *left;
    struct CenterPoint *right;
} CenterPoint;

CenterPoint *buildTree(Node *head, int start, int end)
{

    if ((head) == NULL || start > end)
    {
        return NULL;
    }

    int mid = (start - end) / 2;
    Node *point = head;

    for (int i = start; i < mid; i++)
    {
        point = point->next;
    }

    CenterPoint *root = (CenterPoint *)malloc(sizeof(CenterPoint));
    root->Info.name = point->Info.name;
    root->Info.age = point->Info.age;
    root->Info.address = point->Info.address;
    root->Info.pNB = point->Info.pNB;

    root->left = buildTree(head, start, mid - 1);
    root->right = buildTree(point->next, mid + 1, end);

    return root;
}

CenterPoint *centerPoint(Node *head)
{

    if (head == NULL)
    {
        return NULL;
    }

    int length = 0;
    Node *node = head;
    while (node->next != NULL)
    {
        node = node->next;
        length++;
    }

    return buildTree(head, 0, length - 1);
}

CenterPoint *binarySearch(CenterPoint *root, char name[20])
{
    static int count = 0;
    count++;
    printf("So lan lap: %d\n", count);

    if (root == NULL)
        return NULL;

    if (!strcmp(root->Info.name, name))
    {
        return root;
    }

    if (strcmp(root->Info.name, name) >= 0)
    {
        return binarySearch(root->left, name);
    }

    if (strcmp(root->Info.name, name) < 0)
    {
        return binarySearch(root->right, name);
    }
}

void main()
{
    Node *head = NULL;
    char name[20];
    printf("Nhap vao ten can tim: ");
    scanf("%s", &name);

    xuLyData(&head);
    CenterPoint *ptr = centerPoint(head);

    CenterPoint *result = binarySearch(ptr, name);
    if (result != NULL)
    {
        printf("Ten: %s\n", result->Info.name);
        printf("Tuoi: %s\n", result->Info.age);
        printf("Dia chi: %s\n", result->Info.address);
        printf("SDT: %s\n", result->Info.pNB);
    }else
        printf("Khong tim thay\n");
}
