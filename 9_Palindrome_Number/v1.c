#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    if(x < 0){
        return false;
    } else if(x == 0){
        return true;
    } else{
        int len = snprintf(NULL, 0, "%lld", x);
        char *numStr = malloc(len + 1);
        snprintf(numStr, len + 1, "%d", x);
        for(int i = 0; i < (len/2); i++){
            if(numStr[i] != numStr[len - i - 1]){
                free(numStr);
                return false;
            }
        }
        free(numStr);
        return true;
    }
}

int main(void) {
    int num = 1000000001;
    
    printf("%d\n", num);
    
    printf("%s\n", isPalindrome(num)? "true" : "false");

    return 0;
}
