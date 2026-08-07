class Solution {
public:
    int f(int idx,int amount,vector<int>&coins,vector<vector<int>>& dp){

        if(amount == 0) return 0;//short circuit
        if(idx == -1) return 1e9; //to discard all the cases which cant make amount 0 till

        if(dp[idx][amount]!=0) return dp[idx][amount];
        //not take
        int nottake = f(idx-1,amount,coins,dp);

        //take
        int take = 1e9;
        if(amount >= coins[idx])
            take = 1+f(idx,amount-coins[idx],coins,dp);

        return dp[idx][amount] = min(take,nottake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        int ans = f(n-1,amount,coins,dp);
        if(ans>=1e9) return -1;
        else return ans;
        //f will ret the min coins req to make up the amount specified
    }
};