/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int find_max(int* arr, int size){
    int max = arr[0];
    for(int j = 1; j < size; j++){
        if(max <= arr[j]){
            max = arr[j];
        }
    }
    return max;
}

bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    bool* result = malloc(candiesSize * sizeof(bool));

    for(int i = 0; i < candiesSize; i++){
        if(candies[i] + extraCandies >= find_max(candies, candiesSize)){
            result[i] = true;
        }else{
            result[i] = false;
        }
    }
    *returnSize = candiesSize;
    return result;
}