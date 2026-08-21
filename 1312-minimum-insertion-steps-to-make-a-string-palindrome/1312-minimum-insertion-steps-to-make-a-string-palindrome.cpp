class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();

        string rev = s;
        reverse(rev.begin(),rev.end());

        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int i1 = 1; i1<=n; i1++){
            for(int i2 = 1; i2<=n; i2++){
                
                if(s[i1-1] == rev[i2-1]){
                    dp[i1][i2] = dp[i1-1][i2-1] + 1;
                }
                else{
                    dp[i1][i2] = max(dp[i1-1][i2],dp[i1][i2-1]);
                }
            }
        }
        return n - dp[n][n];
    }
};