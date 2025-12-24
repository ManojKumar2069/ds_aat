#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *a;
    int f;
    int r;
    int k;
} MyCircularQueue;

/* prototypes */
MyCircularQueue* myCircularQueueCreate(int k);
bool myCircularQueueEnQueue(MyCircularQueue* q, int x);
bool myCircularQueueDeQueue(MyCircularQueue* q);
int myCircularQueueFront(MyCircularQueue* q);
int myCircularQueueRear(MyCircularQueue* q);
bool myCircularQueueIsEmpty(MyCircularQueue* q);
bool myCircularQueueIsFull(MyCircularQueue* q);
void myCircularQueueFree(MyCircularQueue* q);

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* q = malloc(sizeof(MyCircularQueue));
    q->a = malloc(sizeof(int) * k);
    q->f = -1;
    q->r = -1;
    q->k = k;
    return q;
}

bool myCircularQueueIsEmpty(MyCircularQueue* q) {
    return q->f == -1;
}

bool myCircularQueueIsFull(MyCircularQueue* q) {
    return (q->r + 1) % q->k == q->f;
}

bool myCircularQueueEnQueue(MyCircularQueue* q, int x) {
    if (myCircularQueueIsFull(q))
        return false;

    if (q->f == -1)
        q->f = 0;

    q->r = (q->r + 1) % q->k;
    q->a[q->r] = x;
    return true;
}

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

int myCircularQueueFront(MyCircularQueue* q) {
    if (myCircularQueueIsEmpty(q))
        return -1;
    return q->a[q->f];
}

int myCircularQueueRear(MyCircularQueue* q) {
    if (myCircularQueueIsEmpty(q))
        return -1;
    return q->a[q->r];
}

void myCircularQueueFree(MyCircularQueue* q) {
    free(q->a);
    free(q);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/
