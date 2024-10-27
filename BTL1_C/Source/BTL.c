#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Header/binarySearch.h"
#include "../Header/buildTree.h"
#include "../Header/handleData.h"



int main()
{
    Node *head = NULL;


    handleData(&head);

    //print_list(head);
    CenterPoint *ptr = centerPoint(head);

    char str[20];
    printf("Nhap ten can tim: ");
    scanf("%s",str);
    CenterPoint *result = binarySearch(ptr, str);
    if (result != NULL) {
        printf("Ten: %s\n", result->inFo.name);
        printf("Tuoi: %s\n", result->inFo.age);
        printf("Dia chi: %s\n", result->inFo.address);
        printf("SDT: %s\n", result->inFo.phNB);
    } else {
         printf("Khong tim thay\n");
    }

    return 0;
}