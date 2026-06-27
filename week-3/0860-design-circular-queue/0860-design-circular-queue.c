


typedef struct {
    int *arr;
    int front;
    int rear;
    int capacity;
    int size;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->arr = (int*)malloc(k * sizeof(int));
    obj->front = 0;
    obj->rear = 0;
    obj->capacity = k;
    obj->size = 0;
    return obj;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if(obj->size == 0)
        return true;
    return false;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj) == true)
        return -1;
    return obj->arr[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    return obj->arr[(obj->rear - 1 + obj->capacity) % obj->capacity];
}


bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if(obj->size == obj->capacity)
        return true;
    return false;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(myCircularQueueIsFull(obj) == true){
        return false;
    }else{
        obj->arr[obj->rear] = value;
        obj->rear = (obj->rear + 1) % obj->capacity;
        obj->size++;
        return true;
    }
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj) == true){
        return false;
    }else{
        obj->front = (obj->front + 1) % obj->capacity;
        obj->size--;
        return true;
    }
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->arr);
    free(obj);
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