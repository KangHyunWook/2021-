#include "queue.h"
#define TRUE 1
#define FALSE 0

typedef uint32_t bool;

int q[MAX_SIZE];

int front;
int rear;

bool isFull() {
    if(front==0 && rear==(MAX_SIZE-1)) 
        return TRUE;
    else if(rear+1==front)
        return TRUE;
    return FALSE;
}

bool isEmpty() {
    return front==rear;
}

void add(int q[], int data) {
    if(isFull()) {
        printf("Queue is full!\n");
    }
    else {
        rear=(rear+1)%MAX_SIZE; //6
        q[rear]=data;
        printf("%d added\n",data);
    } 
}

int pop(int q[]) {
    if(isEmpty()) {
        printf("Queue is Empty! ");
        return 0;
    }

    front=(front+1)%MAX_SIZE;
    return q[front];
}












