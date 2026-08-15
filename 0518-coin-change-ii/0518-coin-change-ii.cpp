class Solution {
public:
    int f(int idx,int amount,vector<int>& coins,vector<vector<int>>& dp){
        if (idx == 0) {
            if (amount % coins[0] == 0) return 1; 
            return 0;
        }

        if(dp[idx][amount]!=-1) return dp[idx][amount];
        //pick
        int pick = 0;
        if(amount>=coins[idx])
            pick = f(idx,amount-coins[idx],coins,dp);

        //not pick
        int notpick = f(idx-1,amount,coins,dp);

        return dp[idx][amount] = pick + notpick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1)); //size cant ever be -1.
        return f(n-1,amount,coins,dp);
    }
};