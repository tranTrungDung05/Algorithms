/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *ans = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    ans[0] = -1;
    ans[1] = -1;

    int first = -1, last = -1;
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] == target) {
            if(first == -1) first = i; 
            last = i;                  
        }
    }

    ans[0] = first;
    ans[1] = last;
    return ans;
}