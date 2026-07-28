char* addBinary(char* a, char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);

    int i = lenA - 1;
    int j = lenB - 1;
    
    int size = ((i + 1) > (j + 1)) ? (i + 1) : (j + 1);

    char *ans = (char*)malloc((size + 2) * sizeof(char));
    int k = size + 1;
    ans[k--] = '\0';
    
    int carry = 0;

    while(i >= 0 || j >= 0 || carry != 0){
        int sum = carry; //a[len_a] + b[len_a] + carry

        if(i >= 0)
            sum += a[i] - '0';

        if(j >= 0)
            sum += b[j] - '0';

        ans[k] = (sum % 2) + '0';
        carry = sum / 2;
        i--;
        j--;
        k--;
    }
    if(k >= 0)
        return ans + 1;
    return ans;
}