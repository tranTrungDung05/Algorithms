int compare(const void* a, const void* b){
    char **ptr1 = (char**)a;
    char **ptr2 = (char**)b;

    char *str1 = *ptr1;
    char *str2 = *ptr2;

    char ab[50], ba[50];

    strcpy(ab, str1);
    strcat(ab, str2);

    strcpy(ba, str2);
    strcat(ba, str1);

    return strcmp(ba, ab);
}
char* largestNumber(int* nums, int numsSize) {
    char **strNum = calloc(1000, sizeof(char*));

    for(int i = 0; i < numsSize; i++){
        strNum[i] =(char*)malloc(20 * sizeof(char));
        sprintf(strNum[i], "%d", nums[i]);
    }
    
    qsort(strNum, numsSize, sizeof(char*), compare);

    if(strcmp(strNum[0], "0") == 0){
        char *exc = malloc(2 * sizeof(char));
        strcpy(exc, "0");
        for(int i = 0; i < numsSize; i++)   free(strNum[i]);
        free(strNum);
        return exc;
    }


    char* ans = calloc(1000, sizeof(char));
    ans[0] = '\0';

    for(int i = 0; i < numsSize; i++){
        strcat(ans, strNum[i]);
        free(strNum[i]);
    }

    free(strNum);
    return ans;
}