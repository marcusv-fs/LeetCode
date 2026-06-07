#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


char* longestCommonPrefix(char** strs, int strsSize) {
    int len = 200;
    char *common = malloc ((len + 1) * sizeof(char));
    bool flag = true;
    common[0] = '\0';
    
    if(strsSize == 1){
        return strs[0];
    }

    for(int i = 0; i < strsSize; i++){
        if(len > strlen(strs[i])){
            len = strlen(strs[i]);
        }
    }

    for(int i = 0; (flag == true && i < len); i++){
        for(int j = 1; j < strsSize; j++){
            if(strs[0][i] == strs[j][i]){
                common[i] = strs[0][i];  
            }else{
                common[i] = '\0';
                flag = false;
                break;
            }
        }
    }
    common[len] = '\0';
    return common;
}

int main(void) {
    char* strs[] = {"ab", "a"};
    char * common = longestCommonPrefix(strs, 2);

    printf("%s", common);
    
    free(common);
    return 0;
}
