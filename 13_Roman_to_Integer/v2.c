#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


int toDecimal[22] = {
    ['I' - 'C'] = 1,
    ['V' - 'C'] = 5,
    ['X' - 'C'] = 10,
    ['L' - 'C'] = 50,
    ['C' - 'C'] = 100,
    ['D' - 'C'] = 500,
    ['M' - 'C'] = 1000
};

int romanToInt(char* s) {
    int v1, v2, result = 0;
    for(int i = 0; s[i] != '\0'; i++){
        v1 = toDecimal[s[i] - 67];
        v2 = (s[i + 1] != '\0')? toDecimal[s[i + 1] - 67] : 0;

        if (v1 < v2){
            result -= v1;
        }else{
            result += v1;
        }
    }
    return result;
}

int main(void) {
    char s[] = "MCMXCIV";    
    printf("%d\n", romanToInt(s));
    return 0;
}
