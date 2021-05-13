/*
    Date: 2021-May-13
    TA: HYUN WOOK KANG
    Course: Data Structures
    Tutorial: Week7
    Description: This program shows an example of
                FixedQueue and CircularQueue.
                gcc main.c fixedqueue.c-> fixedqueue example.
                gcc main.c circularqueue.c ->circularqueue example.
*/

#include "queue.h"

int main() {
    extern int q[MAX_SIZE];
    add(q, 5);
    add(q, 3);
    add(q, 7);
    add(q, 2);
    add(q, 6);
    printf("pop: %d\n",pop(q));
    printf("pop: %d\n",pop(q));
    add(q, 1);
    printf("pop: %d\n",pop(q));
    printf("pop: %d\n",pop(q));
    printf("pop: %d\n",pop(q));
    printf("pop: %d\n",pop(q));    
    printf("pop: %d\n",pop(q));
    add(q,8);
    printf("pop: %d\n",pop(q));

}












