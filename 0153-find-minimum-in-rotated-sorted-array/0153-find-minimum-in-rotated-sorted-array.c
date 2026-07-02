int findMinEle(int *nums, int numsSize){
    int min = nums[0];
    for(int i = 1; i < numsSize; i++){
        if(nums[i] < min){
            min = nums[i];
        }
    }
    return min;
}
int findMin(int* nums, int numsSize) {
    int min = findMinEle(nums, numsSize);
    int min_idx = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] == min){
            min_idx = min;
            break;
        }
    }
    return min_idx;
}