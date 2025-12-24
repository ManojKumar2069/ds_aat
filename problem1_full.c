#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *a;
    int f;
    int r;
    int k;
} MyCircularQueue;

/* Function prototypes */
MyCircularQueue* myCircularQueueCreate(int k);
bool myCircularQueueEnQueue(MyCircularQueue* q, int x);
bool myCircularQueueDeQueue(MyCircularQueue* q);
int myCircularQueueFront(MyCircularQueue* q);
int myCircularQueueRear(MyCircularQueue* q);
bool myCircularQueueIsEmpty(MyCircularQueue* q);
bool myCircularQueueIsFull(MyCircularQueue* q);
void myCircularQueueFree(MyCircularQueue* q);

/* Create queue */
MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    q->a = (int*)malloc(sizeof(int) * k);
    q->f = -1;
    q->r = -1;
    q->k = k;
    return q;
}

/* Check empty */
bool myCircularQueueIsEmpty(MyCircularQueue* q) {
    return q->f == -1;
}

/* Check full */
bool myCircularQueueIsFull(MyCircularQueue* q) {
    return (q->r + 1) % q->k == q->f;
}

/* Enqueue */
bool myCircularQueueEnQueue(MyCircularQueue* q, int x) {
    if (myCircularQueueIsFull(q))
        return false;

    if (q->f == -1)
        q->f = 0;

    q->r = (q->r + 1) % q->k;
    q->a[q->r] = x;
    return true;
}

/* Dequeue */
bool myCircularQueueDeQueue(MyCircularQueue* q) {
    if (myCircularQueueIsEmpty(q))
        return false;

    if (q->f == q->r) {
        q->f = -1;
        q->r = -1;
    } else {
        q->f = (q->f + 1) % q->k;
    }
    return true;
}

/* Front */
int myCircularQueueFront(MyCircularQueue* q) {
    if (myCircularQueueIsEmpty(q))
        return -1;
    return q->a[q->f];
}

/* Rear */
int myCircularQueueRear(MyCircularQueue* q) {
    if (myCircularQueueIsEmpty(q))
        return -1;
    return q->a[q->r];
}

/* Free memory */
void myCircularQueueFree(MyCircularQueue* q) {
    free(q->a);
    free(q);
}

/* -------- MAIN FUNCTION -------- */
int main() {
    MyCircularQueue* q = myCircularQueueCreate(5);

    printf("Enqueue 10: %d\n", myCircularQueueEnQueue(q, 10));
    printf("Enqueue 20: %d\n", myCircularQueueEnQueue(q, 20));
    printf("Enqueue 30: %d\n", myCircularQueueEnQueue(q, 30));
    printf("Enqueue 40: %d\n", myCircularQueueEnQueue(q, 40));
    printf("Enqueue 50: %d\n", myCircularQueueEnQueue(q, 50));
    printf("Enqueue 60 (Full): %d\n", myCircularQueueEnQueue(q, 60));

    printf("Front: %d\n", myCircularQueueFront(q));
    printf("Rear: %d\n", myCircularQueueRear(q));

    printf("Dequeue: %d\n", myCircularQueueDeQueue(q));
    printf("Dequeue: %d\n", myCircularQueueDeQueue(q));

    printf("Front after dequeue: %d\n", myCircularQueueFront(q));
    printf("Rear after dequeue: %d\n", myCircularQueueRear(q));

    myCircularQueueFree(q);
    return 0;
}
