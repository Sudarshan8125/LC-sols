class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i1 = 1; i1<=n; i1++){
            for(int i2 = 1; i2<=m; i2++){
                
                if(word1[i1-1] == word2[i2-1]){
                    dp[i1][i2] = dp[i1-1][i2-1] + 1;
                }
                else{
                    dp[i1][i2] = max(dp[i1-1][i2],dp[i1][i2-1]);
                }
            }
        }
        return n + m - 2*dp[n][m]; //max-common => max = del all of 1, add all of 2
    }
};