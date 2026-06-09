/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int* ans = (int*)malloc(temperaturesSize * sizeof(int));

    for (int i = 0; i < temperaturesSize; i++) {
        ans[i] = 0;
    }

    int stack[temperaturesSize];
    int top = -1;

    for(int i = 0; i < temperaturesSize; i++){
        while(top >= 0 && temperatures[i] > temperatures[stack[top]]){
            int prev_idx = stack[top--];
            ans[prev_idx] = i - prev_idx;
        }

        stack[++top] = i;
    }
    *returnSize = temperaturesSize;
    return ans;
}