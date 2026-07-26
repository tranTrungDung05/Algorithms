/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int carry = 1;
    int i = digitsSize - 1;

    while(i >= 0 && carry != 0){
        digits[i] += carry;

        if(digits[i] < 10){
            carry = 0;
        }else if(digits[i] > 10){
            digits[i] = 0;
            carry = 1;
            i--;
        }
    }

    if(digits[0] == 0){
        int *plus = (int*)malloc((digitsSize + 1) * sizeof(int));
        plus[0] = 1;
        int j = 0;
        for(int i = 1; i < digitsSize + 1; i++){
            plus[i] = digits[j++];
        }
        *returnSize = digitsSize + 1;
        return plus;
    }

    *returnSize = digitsSize;
    return digits;
}