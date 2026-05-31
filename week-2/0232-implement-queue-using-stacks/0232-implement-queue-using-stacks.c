


typedef struct {
    int front; 
    int rear;
    int size;
    int *data;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue *q = malloc(sizeof(MyQueue));
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->data = malloc(100 * sizeof(int));
    return q;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->rear++;
    obj->data[obj->rear] = x;
    obj->size++;
}

int myQueuePop(MyQueue* obj) {
    int val = obj->data[obj->front];
    obj->front++;
    obj->size--;
    return val;
}

int myQueuePeek(MyQueue* obj) {
    return obj->data[obj->front];
}

bool myQueueEmpty(MyQueue* obj) {
    if(obj->size > 0)
        return false;
    return true;
}

void myQueueFree(MyQueue* obj) {
    free(obj->data);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/