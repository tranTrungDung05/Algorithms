/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool isCollision(int a, int b) {
    if(a > 0 && b < 0) 
        return true;
    else 
        return false;
}

int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    int *stack = malloc(asteroidsSize * sizeof(int));
    int top = -1;
    bool alive = true;
    for(int i = 0; i < asteroidsSize; i++){
        while(top >= 0 && isCollision(stack[top], asteroids[i]) && alive == true) 
        {
            //combat
            if(abs(stack[top]) < abs(asteroids[i]))
                top--;
            else if (abs(stack[top]) > abs(asteroids[i]))
                alive = false;
            else{
                top--;
                alive = false;
            }
        }

        if(alive == true)
            stack[++top] = asteroids[i];
        else
            alive = true;
    }
    *returnSize = top + 1;
    return stack;
}