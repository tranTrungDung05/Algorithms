#include <string.h>

char* removeDuplicates(char* s, int k) {
    int n = strlen(s);
    int top = -1;
    char *stack = malloc((n + 1) * sizeof(char));
    int *hash = malloc((n + 1) * sizeof(int));

    for(int i = 0; s[i] != '\0'; i++){
        if(top != -1 && stack[top] == s[i]){
            stack[++top] = s[i];
            hash[top] = hash[top - 1] + 1;
        }else{
            stack[++top] = s[i];
            hash[top] = 1;
        }

        if(hash[top] >= k){
            top -= k;
        }
    }

    stack[top + 1] = '\0';
    return stack;
}