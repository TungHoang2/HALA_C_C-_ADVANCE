#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *item;
    int size;
    int top;
} Stack;

void initialize(Stack *stack, int size){
    stack ->item = (int*)malloc(size*sizeof(int));
    stack ->size = size;
    stack ->top = -1;
}

int isFull(Stack stack){
    return stack.top == stack.size -1;

}

int isEmpty(Stack stack){
    return stack.top == -1;
}

void push(Stack *stack,int value){
    if (!isFull(*stack))
    {
        stack -> item[++stack->top] = value;
        printf("Add successful\n");
    }else{
        printf("Stack overflow");
    }
}

int pop(Stack *stack){
    if(!isEmpty(*stack)){
        return stack->item[stack->top--];
    }else{
        printf("stack underflow");
        return -1;
    }
}

int top(Stack stack){
    if(!isEmpty(stack)){
        return stack.item[stack.top];
    }else{
        printf("Stack is empty");
        return -1;
    }
}

int main(){
    Stack stack1;
    initialize(&stack1, 5);

    push(&stack1,10);
    push(&stack1,20);
    push(&stack1,30);
    push(&stack1,40);
    push(&stack1,50);

    printf("Pop element:%d\n",pop(&stack1));
    printf("Top element:%d\n", top(stack1));
}



