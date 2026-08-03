class Solution {
public:
    int ways(int n,vector<int>& dp){
        if(n==0) return 1;
        if(n==1) return 1;

        if(dp[n]!=-1) return dp[n];
        int l = ways(n-1,dp);
        int r = ways(n-2,dp);
        return dp[n] = l+r;
    }


    int climbStairs(int n) {
        int sum = 0;
        // do memoization means make array and store inputs
        vector<int> dp(n+1,-1);
        return ways(n,dp);
    }
};