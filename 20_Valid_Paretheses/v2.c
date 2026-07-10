#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char* s) {
    char stack[10000];
    int top = -1;
    int n = strlen(s);
    for(int i = 0; i < n; i++){
        switch (s[i]){
            case '(':
                stack[++top] = ')';
                break;
            case '[':
                stack[++top] = ']';
                break;
            case '{':
                stack[++top] = '}';
                break;
            default:
                if (top < 0 || stack[top--] != s[i])
                    return false;
        }
    }
    return top == -1;;
}
int main(void) {
    char s[] = "{()}";    
    printf("%s", isValid(s)? "true" : "false");
    return 0;
}