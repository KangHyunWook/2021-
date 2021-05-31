#ifndef QUEUE_H
#define QUEUE_H

typedef int itemType;
typedef struct QueueType *qPointer;

qPointer queue_create();

struct Queue_ADT {
    qPointer (*create)();
    void (*add)(qPointer, itemType data);
    itemType (*front)(qPointer);
    void (*pop)(qPointer);
} queue_api;


#endif
