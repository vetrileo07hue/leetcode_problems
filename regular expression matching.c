#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isMatch(char* s, char* p) {
    int m = strlen(s);
    int n = strlen(p);

    // Dynamically allocate memory for the 2D DP matrix: (m + 1) x (n + 1)
    bool** dp = (bool**)malloc((m + 1) * sizeof(bool*));
    for (int i = 0; i <= m; i++) {
        dp[i] = (bool*)calloc((n + 1), sizeof(bool)); // Initialize all elements to false
    }

    // Base case: empty string matches empty pattern
    dp[0][0] = true;

    // Handle patterns like a*, a*b*, or a*b*c* matching an empty string
    for (int j = 2; j <= n; j++) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2];
        }
    }

    // Fill the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            // Case 1: Elements match directly, or pattern has a dot '.'
            if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                dp[i][j] = dp[i - 1][j - 1];
            } 
            // Case 2: Pattern contains an asterisk '*'
            else if (p[j - 1] == '*') {
                // Match 0 times: eliminate the preceding character and '*'
                dp[i][j] = dp[i][j - 2];

                // Match 1 or more times: check if preceding pattern character matches string character
                if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
            }
        }
    }

    // Store final boolean result
    bool result = dp[m][n];

    // Explicitly free the allocated heap memory to avoid leaks
    for (int i = 0; i <= m; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}
