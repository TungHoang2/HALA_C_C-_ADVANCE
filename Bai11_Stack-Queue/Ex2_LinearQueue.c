#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int *item;
    int front;
    int rear;
    int size;
}Queue;

void initialized(Queue *queue, int size){
    queue ->item =(int*)malloc(size*sizeof(int));
    queue ->front = queue ->rear = -1;
    queue -> size = size;
}

int isEmpty(Queue queue){
    return (((queue.front = queue.rear) == -1) || (queue.front > queue.rear));  
}

int isFull(Queue queue){
    return queue.rear == queue.size - 1;
}

void enqueue(Queue *queue, int value){
    if(isFull(*queue)){
        printf("Queue is full\n");
        return;
    }else{
        if((queue->front == -1) && (queue->rear == -1)){
            queue->front = queue->rear = 0;
        }else{
            queue->rear++;
        }
        queue->item[queue->rear] = value;
        printf("Enqueue: %d\n",value);
    }
}

void dequeue(Queue *queue){
    if(isEmpty(*queue)){
        printf("Queue is empty!\n");
    }else{
        if(queue->front == queue->rear){
            queue->front = queue->rear = -1;
        }
        int value = queue->item[queue->front++];
        printf("Dequeue: %d\n", value);
    }
}

void display(Queue queue){
    if(isEmpty(queue)){
        printf("Queue is empty");
    }else{
        printf("Queue element: ");
        for(int i= queue.front; i<= queue.rear;i++){
            printf("%d ",queue.item[i]);
        }
    }
}

int main(){
    Queue queue1;

    initialized(&queue1,5);
    enqueue(&queue1,10);
    enqueue(&queue1,20);
    enqueue(&queue1,30);
    enqueue(&queue1,40);
    enqueue(&queue1,50);
    dequeue(&queue1);
    enqueue(&queue1,60);

    display(queue1);

}



