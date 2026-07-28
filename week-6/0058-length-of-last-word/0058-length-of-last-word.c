int lengthOfLastWord(char* s) {
    int length = strlen(s) - 1;
    
    for(int i = length; i >= 0; i--){
        if(s[i] != ' ')
            break;
        length -= 1;
    }

    for(int i = length; i >= 0; i--){
        if(s[i] == ' ')
            return length - i;
    }
    
    return length + 1;
}