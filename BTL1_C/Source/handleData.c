#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <../Header/handleData.h>

void handleData(Node **head)
{

    FILE *fp;
    char line[1024];

    // Mở file
    fp = fopen("information.csv", "r");
    if (fp == NULL)
    {
        printf("Lỗi khi mở file!\n");
        return;
    }
    // Đọc từng dòng và xử lý
    fgets(line, sizeof(line), fp);
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        // Tạo nút mới
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->inFo.name = NULL;
        new_node->inFo.age = NULL;
        new_node->inFo.address = NULL;
        new_node->inFo.phNB = NULL;
        new_node->next = NULL;

        // Phân tích chuỗi bằng strtok
        char *token = strtok(line, ",");
        if (token != NULL)
            new_node->inFo.name = strdup(token);

        token = strtok(NULL, ",");
        if (token != NULL)
            new_node->inFo.age = strdup(token);

        token = strtok(NULL, ",");
        if (token != NULL)
            new_node->inFo.address = strdup(token);

        token = strtok(NULL, ",");
        if (token != NULL)
            new_node->inFo.phNB = strdup(token);

        // Thêm nút mới vào danh sách liên kết theo thứ tự tăng dần
        if (*head == NULL || strcmp((*head)->inFo.name, new_node->inFo.name) >= 0)
        {
            new_node->next = *head;
            *head = new_node;
        }
        else
        {
            Node *current = *head;
            while (current->next != NULL && strcmp(current->next->inFo.name, new_node->inFo.name) < 0)
            {
                current = current->next;
            }
            new_node->next = current->next;
            current->next = new_node;
        }
    }
    fclose(fp);
}
