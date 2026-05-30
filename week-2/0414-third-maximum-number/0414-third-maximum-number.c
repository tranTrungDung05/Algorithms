int compare(const void *a, const void *b){
    int x = *(int*)a;
    int y = *(int*)b;
    if(x < y) return 1;
    if(x > y) return -1;
    return 0;
}

int thirdMax(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    int idx = 1;

    for(int i = 1; i < numsSize; i++){
        if(nums[i] != nums[i - 1]){
            idx++;
        }

        if(idx == 3){
            return nums[i];
        }
    }

    return nums[0];
}