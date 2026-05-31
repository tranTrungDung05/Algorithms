


typedef struct {
    int idx;
    int size;
    int *data;
} MyStack;

MyStack* myStackCreate() {
    MyStack *stack = malloc(sizeof(MyStack));
    stack->idx = -1;
    stack->size = 0;
    stack->data = malloc(100 * sizeof(int));
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    obj->idx++;
    obj->size++;
    obj->data[obj->idx] = x;
}

int myStackPop(MyStack* obj) {
    int val = obj->data[obj->idx];
    obj->data[obj->idx] = '\0';
    obj->idx--;
    obj->size--;
    return val;
}

int myStackTop(MyStack* obj) {
    return obj->data[obj->idx];
}

bool myStackEmpty(MyStack* obj) {
    if(obj->size > 0)
        return false;
    return true;
}

void myStackFree(MyStack* obj) {
    free(obj->data);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/