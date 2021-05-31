#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "queue.h"

typedef struct Node {
    itemType data;
    struct Node* next;
} Node;

struct QueueType {
    Node *head;
    Node *tail;
};

qPointer queue_create() {
    qPointer q = malloc(sizeof(struct QueueType));
    q->head=NULL;
    q->tail=NULL;

    return q;
}

void queue_add(qPointer q, itemType data) {
    if(q->head==NULL) {
        q->head=malloc(sizeof(Node));
        q->head->data = data;
    }
    else {
        if(q->tail) {
            q->tail->next=malloc(sizeof(Node));
            q->tail=q->tail->next;
        }
        else{
          q->tail=malloc(sizeof(Node));
          q->tail->data=data;
          printf("add: %d\n", q->tail->data);
        }
        q->tail->data=data;
        q->tail->next=NULL;
    }
}

itemType queue_front(qPointer q) {
    assert(q->head);
    return q->head->data;
}

void queue_pop(qPointer q) {
    assert(q->head);
    q->head=q->tail;
    if(q->head)
        q->tail=q->tail->next;
    // assert(q->tail);
}

struct Queue_ADT queue_api = {
    .create=queue_create,
    .add = queue_add,
    .front = queue_front,
    .pop = queue_pop
};




//
