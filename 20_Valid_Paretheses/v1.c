#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char* s) {
    int expected_pa = 0;
    int expected_co = 0;
    int expected_ch = 0;
    char stack[10000];
    int top = -1;
    char c = 'a';
    for(int i = 0; i < strlen(s); i++){
        switch (s[i]){
            case '(':
                expected_pa++;
                stack[++top] = s[i];
                break;
            case '[':
                expected_co++;
                stack[++top] = s[i];
                break;
            case '{':
                expected_ch++;
                stack[++top] = s[i];
                break;
            case ')':
                if (top < 0 || stack[top] != '('){
                    return false;
                }
                stack[top--];
                expected_pa--;
                break;
            case ']':
                if (top < 0 || stack[top] != '['){
                    return false;
                }
                stack[top--];
                expected_co--;
                break;
            case '}':
                if (top < 0 || stack[top] != '{'){
                    return false;
                }
                stack[top--];
                expected_ch--;
                break;
        }
        if(expected_pa < 0 || expected_co < 0 || expected_ch < 0){
            return false;
        }
    }
    if(expected_pa > 0 || expected_co > 0 || expected_ch > 0){
            return false;
        }
    return true;
}
int main(void) {
    char s[] = "{()}";    
    printf("%s", isValid(s)? "true" : "false");
    return 0;
}
