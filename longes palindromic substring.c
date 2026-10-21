char* longestPalindrome(char* s) {
    int start = 0;
    int maxLen = 1;
    int n = strlen(s);
    
    for (int i = 0; i < n; i++) {

        // Odd length
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r]) {
            if (r - l + 1 > maxLen) {
                start = l;
                maxLen = r - l + 1;
            }
            l--;
            r++;
        }

        // Even length
        l = i;
        r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r]) {
            if (r - l + 1 > maxLen) {
                start = l;
                maxLen = r - l + 1;
            }
            l--;
            r++;
        }
    }

    s[start + maxLen] = '\0';
    return s + start;
}
