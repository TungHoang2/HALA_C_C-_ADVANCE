#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createNode(int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void push_back(Node** array, int value){
    Node* temp = createNode(value);

    if(*array == NULL){

        *array = temp;
    }else{
        Node* p = *array;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp; 
    }
}

void push_front(Node **array, int value){
    Node* temp = createNode(value);

    if(*array == NULL){
        *array = temp;
    }else{
        temp->next = *array;
    }
    *array = temp;
}

void pop_back(Node **array){
    if(*array == NULL){
        printf("Khong co node nao");
    }else{
        Node* p = *array;
        while(p->next->next != NULL){
            p = p->next;
        }
        p->next = NULL;
    }
}

void pop_front(Node **array){
    if(*array == NULL){
        printf("Khong co node nao");
    }else{
        Node *p = *array;
        *array = p->next;
    }
}

int front(Node *array){
    if(array ==NULL){
        return -1;
    }else{
        int front = array->data;
        return front;
    }
}

int back(Node *array){
    if(array ==NULL){
        return -1;
    }else{
        Node* p = array;
        while(p->next != NULL){
            p= p->next;
        }
        return p->data;
    }
}

void insert(Node **array, int value, int pos){
    Node* temp = createNode(value);
    if(pos ==1) {
        push_front(array,value);
    }else{
        Node* p = *array;
        int count=0;
        for(int j=0;j<pos-1;j++)
        {
            p = p->next;
            count++;
        }

        Node* p1 = *array;
        for(int i =0; i< count-1;i++){
            p1 = p1->next;
        }
    
        p1->next = temp;
        temp->next = p;
    }
    
}

void delete_list(Node **array, int pos){// xoa 1 node tai mot vi tri bat ky
    if(pos == 1){
        pop_front(array);
    }else{
        Node* p = *array;
        int count=0;
        for(int j=0;j<pos;j++)
        {
            p = p->next;
            count++;
        }


        Node* p1 = *array;
        for(int i =0; i< count-2;i++){
            p1 = p1->next;
        }

        p1->next = NULL;
        p1->next = p;
    }
}

int size(Node *array){ // lay kich thuoc cua list
    if(array == NULL){
        return -1;
    }else{
        int count=1;
        Node* p = array;
        while(p->next != NULL){
            p = p->next;
            count++;
        }
    return count;
    }
}

int get(Node *array, int pos){
    if(array == NULL){
        return -1;
    }else{
        if(pos > size(array)){
            return -1;
        }else{
            Node* p = array;
            for(int i=0; i<pos-1;i++){
                p = p->next;
            }
            return p->data;
        }
    }
}

bool empty(Node *array){// kiem tra list co rong hay khong
    if(array == NULL){
        return true;
    }else return false;
} 


void printList(Node* array){
    Node* p = array;
    int i =0;
    while(p != NULL){
        printf("Node %d: %d\n",i,p->data);
        p = p->next;
        i++;
    }
}


void main(){
    Node *arr = NULL;
    //Node* n1 = createNode(5);
    //Node* n2 = createNode(10);
    //Node* n3 = createNode(15);
    
   // n1->next = n2;
    //n2->next = n3;
    push_back(&arr,6);
    push_back(&arr,5);
    push_back(&arr,7);
    push_back(&arr,10);
    push_back(&arr,20);
    // push_front(&arr,10);
    // push_front(&arr,20);
    // pop_front(&arr);
    insert(&arr,8,2);
    //delete_list(&arr,2);
    //delete_list(&arr,4);
    //delete_list(&arr,1);
    //pop_back(&arr);
    
    printList(arr);
    printf("data: %d\n",get(arr,5));
}

