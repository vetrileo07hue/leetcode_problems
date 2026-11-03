#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        return "";
    }

    char* prefix = strs[0];
    int len = strlen(prefix);

    for (int i = 1; i < strsSize; i++) {
        while (strncmp(prefix, strs[i], len) != 0) {
            len--;
            if (len == 0) {
                return "";
            }
        }
    }

    char* result = (char*)malloc((len + 1) * sizeof(char));
    strncpy(result, prefix, len);
    result[len] = '\0'; 

    return result;
}
