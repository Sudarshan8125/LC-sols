class Solution {
public:
    int f(int idx,int amount,vector<int>& coins,vector<vector<int>>& dp){
        if(amount == 0) return 0; //to make amount 0 =>min length we pick is 0.
        if(idx<0) return 1e9;

        if(dp[idx][amount]!=-1) return dp[idx][amount];
        //pick
        int pick = 1e9;
        if(amount>=coins[idx])
            pick = 1 + f(idx,amount-coins[idx],coins,dp);

        //not pick
        int notpick = f(idx-1,amount,coins,dp);

        return dp[idx][amount] = min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1)); //size cant ever be -1.
        int ans = f(n-1,amount,coins,dp);
        return ans>=1e9 ? -1:ans;
    }
};