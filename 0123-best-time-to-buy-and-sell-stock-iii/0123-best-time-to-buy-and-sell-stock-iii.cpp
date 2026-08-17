class Solution {
public:
    int f(int idx,int buy,vector<int>& prices,int n,vector<vector<int>>& dp){
        if(idx==n || buy==0){
            return 0;
        }

        if(dp[idx][buy]!=-1) return dp[idx][buy];
        int profit = 0;
        if(buy%2==0){
            int b = -prices[idx] + f(idx+1,buy-1,prices,n,dp);
            int nb = f(idx+1,buy,prices,n,dp);
            profit = max(b,nb);
        }
        else{
            int s = +prices[idx] + f(idx+1,buy-1,prices,n,dp);
            int ns = f(idx+1,buy,prices,n,dp);
            profit = max(s,ns);
        }
        return dp[idx][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        //try out all ways
        int n = prices.size();
        //even b buy
        //odd b sell
        vector<vector<int>> dp(n,vector<int>(5,-1)); //up until b==4
        return f(0,4,prices,n,dp); //with buy permission
    }
};