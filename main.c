/*
    DATE: 2021-May-21
    TA: HYUN WOOK KANG
    Tutorial: Week9
    Description: This program shows a practical example
                of Linked queue implementation.
*/

#include <stdio.h>
#include <assert.h>

#include "queue.h"
int main() {
    qPointer queue=queue_api.create();
    // assert(-1);
    queue_api.add(queue, 2);
    queue_api.add(queue, 5);
    printf("front: %d\n", queue_api.front(queue));
    queue_api.pop(queue);
    printf("front: %d\n", queue_api.front(queue));
    printf("front: %d\n", queue_api.front(queue));
    queue_api.pop(queue);
    queue_api.pop(queue);
    // printf("front: %d\n", queue_api.front(queue));
}
