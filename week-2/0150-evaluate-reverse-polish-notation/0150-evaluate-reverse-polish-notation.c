int evalRPN(char** tokens, int tokensSize) {
    int stack[tokensSize];
    int top = -1;

    for(int i = 0; i < tokensSize; i++){
        if(strcmp(tokens[i], "+") == 0)
        {
            int a = stack[top--];
            int b = stack[top--];

            stack[++top] = (a + b);
        }else if(strcmp(tokens[i], "-") == 0){
            int a = stack[top--];
            int b = stack[top--];

            stack[++top] = (b - a);
        }else if(strcmp(tokens[i], "*") == 0){
            int a = stack[top--];
            int b = stack[top--];

            stack[++top] = (a * b);
        }else if(strcmp(tokens[i], "/") == 0){
            int a = stack[top--];
            int b = stack[top--];

            stack[++top] = (b / a);
        }else{
            stack[++top] = atoi(tokens[i]);
        }
    }

    return stack[top];
}