#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    int maxLength = 0;
    int left = 0; 
    
    int lastSeen[256];
    for (int i = 0; i < 256; i++) {
        lastSeen[i] = -1;
    }

    for (int right = 0; right < n; right++) {
        char currentChar = s[right];

        if (lastSeen[(unsigned char)currentChar] >= left) {
            left = lastSeen[(unsigned char)currentChar] + 1;
        }

        lastSeen[(unsigned char)currentChar] = right;

        int currentLength = right - left + 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }

    return maxLength;
}
