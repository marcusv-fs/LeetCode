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
    int result = 0;
    int v1, v2;
    int len = strlen(s);
    if(len == 1){
        result += toDecimal[s[len - 1] - 67]; 
    }else{
        for(int i = 0; i < len - 1; i++){
            v1 = toDecimal[s[i] - 67];
            v2 = toDecimal[s[i + 1] - 67];

            switch(v1){
                case 1:
                {
                    if(v2 == 5){
                        v1 = 4;
                        v2 = 0;
                        i++;
                        break;
                    }
                    if(v2 == 10){
                        v1 = 9;
                        v2 = 0;
                        i++;
                        break;
                    }
                    break;
                }
                case 10:
                {
                    if(v2 == 50){
                        v1 = 40;
                        v2 = 0;
                        i++;
                        break;
                    }
                    if(v2 == 100){
                        v1 = 90;
                        v2 = 0;
                        i++;
                        break;
                    }
                    break;
                }
                case 100:
                {
                    if(v2 == 500){
                        v1 = 400;
                        v2 = 0;
                        i++;
                        break;
                    }
                    if(v2 == 1000){
                        v1 = 900;
                        v2 = 0;
                        i++;
                        break;
                    }
                    break;
                }
            }
            result += v1;
            if(i + 2 == len){
                result += toDecimal[s[len - 1] - 67];  
            }
        } 
    }
     
    
    return result;
}

int main(void) {
    char s[] = "MCMXCIV";    
    printf("%d\n", romanToInt(s));
    return 0;
}
