class Solution {
public:
    int climbStairs(int n) {
        int sum = 0;
        // do memoization means make array and store inputs
        vector<int> dp(n+1,-1);

        //converting to tabulation 
        dp[0] = 1; //from base cases to the top
        dp[1] = 1;

        for(int i = 2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};