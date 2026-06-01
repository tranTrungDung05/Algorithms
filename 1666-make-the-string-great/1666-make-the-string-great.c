bool notGood(char a, char b){
    return abs(a - b) == 32;
}
char* makeGood(char* s) {
    int top = -1;

    for(int i = 0; s[i] != '\0'; i++){
        if(top >= 0 && notGood(s[i], s[top])){
            top--;
        }else{
            s[++top] = s[i];
        }
    }
    s[top + 1] = '\0';
    return s;
}
