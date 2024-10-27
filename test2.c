#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct Task
{
    int t_start;
    int t_end;
} Task;

void generateTask(Task *tasks, int N, int t_end)
{
    for (int i = 0; i < N; i++)
    {
        do {
            tasks[i].t_start = rand() % 1441;  // Thời gian bắt đầu (0 - 1440 phút)
            tasks[i].t_end = tasks[i].t_start + rand() % 500 + 1;  // Thời gian kết thúc
        } while (tasks[i].t_end > t_end);  // Lặp lại nếu t_end vượt giới hạn
    }
}



void bubbleSort(Task *tasks, int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (tasks[j].t_end > tasks[j + 1].t_end)
            {
                Task temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }
}

void maxTask(Task *tasks, int N)
{
    bubbleSort(tasks, N);

    int current_end = -1;
    int count =0;
    for (int i = 0; i < N; i++)
    {
        if (tasks[i].t_start > current_end)
        {
            printf("(%d; %d)\n", tasks[i].t_start, tasks[i].t_end);
            count++;
            current_end = tasks[i].t_end;
        }
    }
    printf("%d\n",count);
}

int main()
{
    srand(time(NULL));

    int N = rand() % 91 + 10;
    int N1 = ceil(N * 30 / 100);
    Task *tasks = (Task *)malloc(N * sizeof(Task));
    printf("Tong so cong viec: %d\n", N);
    generateTask(tasks, N1, 720);
    generateTask(tasks + N1, (N - N1), 1440);
    for (int i = 0; i < N; i++)
    {
        printf("(%d; %d)\n", tasks[i].t_start, tasks[i].t_end);
    }
    printf("So luong cong viec toi da: \n");
    maxTask(tasks, N);
    free(tasks);
}