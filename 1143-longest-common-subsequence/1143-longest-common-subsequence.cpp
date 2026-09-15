class Solution {
public:
    int f(int idx1,int idx2,string& s1,string& s2,vector<vector<int>>& dp){
        if(idx1 == 0 || idx2 == 0) return 0;

        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];

        if(s1[idx1-1] == s2[idx2-1]){
            return dp[idx1][idx2] = 1 + f(idx1-1,idx2-1,s1,s2,dp);
        }

        return dp[idx1][idx2] = max(f(idx1-1,idx2,s1,s2,dp), f(idx1,idx2-1,s1,s2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(n,m,text1,text2,dp);
    }
};