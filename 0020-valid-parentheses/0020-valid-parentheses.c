int count_s(char *s){
    int count = 0;
    for(int i = 0 ; s[i] != '\0'; i++){
        count++;
    }
    return count;
}

bool isValid(char* s) {
    if(s == NULL || s[0] == '\0' || s[1] == '\0'|| count_s(s) % 2 != 0) return false;

    char stack[count_s(s)];
    int top = -1;

    //process for each element
    for(int i = 0; s[i] != '\0'; i++){
        //push condition (no need to push all element into stack, so push first)
        if(s[i] == '{' || s[i] == '[' || s[i] == '('  )
        {
            stack[++top] = s[i];
        }
        //pop condition
        else if (top >= 0    &&
                (s[i] == '}' && stack[top] == '{' ||
                 s[i] == ']' && stack[top] == '[' ||
                 s[i] == ')' && stack[top] == '(' ))
        {
            top--;
        }else{
            //if closed brackets unmatch opened backets (opposite of else if condition above)
            return false;
        }
    }
    printf("top = %d", top);
    //stack still not empty
    return top == -1;
}