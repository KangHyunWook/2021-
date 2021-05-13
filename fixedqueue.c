#include "queue.h"
#define isEmpty() front==rear
#define isFull() rear==MAX_SIZE

int q[MAX_SIZE];
int front;
int rear;

void add(int q[], int data){
    if(isFull()) {
        fprintf(stderr, "%s", "Queue is full\n");
        return;
    }
    q[rear++]=data;
}

int pop(int q[]) {
    if(isEmpty()) {
        fprintf(stderr, "%s", "Queue is Empty\n\
Program exits!\n");
        exit(1);
    }
    return q[front++];
}