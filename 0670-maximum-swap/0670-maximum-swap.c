int maximumSwap(int num) {
    char s[20];
    sprintf(s, "%d", num);
    int n = strlen(s);

    int hash[10];
    for(int i = 0; i < 10; i++){
        hash[i] = -1;
    }

    for(int i = 0; i < n; i++)
    {
        hash[s[i] - '0'] = i;
    }

    for(int i = 0; i < n; i++){
        for(int j = 9; j > s[i] - '0'; j--){
            if(hash[j] > i){
                char temp = s[i];
                s[i] = s[hash[j]];
                s[hash[j]] = temp;
                return atoi(s);
            }
        }
    }
    return num;
}