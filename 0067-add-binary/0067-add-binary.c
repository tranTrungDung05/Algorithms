char* addBinary(char* a, char* b) {
    int len_a = strlen(a) - 1;
    int len_b = strlen(b) - 1;
    
    int carry = 0;

    int size = ((len_a + 1) > (len_b + 1)) ? (len_a + 1) : (len_b + 1);
    char *ans = (char*)malloc((size + 2) * sizeof(char));
    int k = size + 1;
    ans[k--] = '\0';

    while(len_a >= 0 || len_b >= 0 || carry != 0){
        int sum = carry; //a[len_a] + b[len_a] + carry

        if(len_a >= 0)
            sum += a[len_a] - '0';

        if(len_b >= 0)
            sum += b[len_b] - '0';

        ans[k] = (sum % 2) + '0';
        carry = sum / 2;
        len_a--;
        len_b--;
        k--;
    }
    if(k >= 0)
        return ans + 1;
    return ans;
}