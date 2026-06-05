#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    if(x < 0 || (x % 10 == 0 && x != 0)){
        return false;
    } else{
        int reverse = 0;
        while (x > reverse){
            reverse = reverse * 10 + x % 10;
            x /= 10;
        }
        return (x == reverse) || (x == reverse / 10);
    }
}

int main(void) {
    int num = 1000000001;
    
    printf("%d\n", num);
    
    printf("%s\n", isPalindrome(num)? "true" : "false");

    return 0;
}
