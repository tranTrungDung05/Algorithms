char* from_int_toString(int x, int *count){
    int temp = x;

    while(temp >= 1){
        temp /= 10;
        (*count)++;
    }
    printf("count = %d", *count);

    char* str = (char*)malloc((*count + 1) * sizeof(char));
    
    for(int i = 0; i < *count; i++){
        str[i] = x % 10 + '0';
        x /= 10;
    }
    return str;
}

bool isPalindrome(int x) {
    if(x < 0){
        return false;
    }

    int len_x = 0;
    char *str_x = from_int_toString(x, &len_x);
    int n = 0;
    int m = len_x - 1;

    while(n < m)
    {
        if(str_x[n] == str_x[m]){
            n++;
            m--;
            continue;
        }else{
            free(str_x);
            return false;
        }
    }
    free(str_x);
    return true;
}
