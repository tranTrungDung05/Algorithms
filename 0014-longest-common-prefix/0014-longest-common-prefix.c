char* longestCommonPrefix(char** strs, int strsSize) {
    int len = strlen(strs[0]);
    char *ans = (char*)malloc((len + 1) * sizeof(char));
    int i;

    for(i = 0; i < len; i++){
        for(int j = 0; j < strsSize; j++){
            if(strs[j][i] == '\0' || strs[j][i] != strs[0][i]){
                ans[i] = '\0';
                return ans;
            }else{
                ans[i] = strs[0][i];
            }
        }
    }

    ans[i] = '\0';
    return ans;
}