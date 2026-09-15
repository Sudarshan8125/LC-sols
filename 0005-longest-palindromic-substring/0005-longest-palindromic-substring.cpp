class Solution {
public:
    string longestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        
        int n = s.length();
        // dp[i][j] stores the length of the common suffix of s[0...i-1] and rev[0...j-1]
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        int max_len = 0;
        int end_idx = 0; // Tracks the ending position in the original string
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == rev[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    
                    // CRITICAL VALIDATION STEP:
                    // Check if the reversed substring aligns with the original substring's position
                    if ((n - j) == (i - dp[i][j])) {
                        if (dp[i][j] > max_len) {
                            max_len = dp[i][j];
                            end_idx = i;
                        }
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        
        // return the substring using starting position and length
        return s.substr(end_idx - max_len, max_len);
    }
};
