int strStr(char* haystack, char* needle) {
    int hay_size = strlen(haystack);
    int nee_size = strlen(needle);

    bool flag = true;

    for(int i = 0; i < hay_size; i++){
        if(haystack[i] == needle[0]){
            for(int j = 0; j < nee_size; j++){
                if(haystack[i + j] == needle[j])
                    continue;
                else{
                    flag = false;
                    break;
                }
            }
            if(flag == true)
                return i;
            else
                flag = true;
        }
    }
    return -1;
}