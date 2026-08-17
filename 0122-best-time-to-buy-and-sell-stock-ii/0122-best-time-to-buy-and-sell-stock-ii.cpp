class Solution {
public:
    int f(int idx,int buy,vector<int>& prices,vector<vector<int>>& dp,int n){
        if(idx==n) return 0;

        if(dp[idx][buy]!=-1) return dp[idx][buy];
        int profit = 0;
        if(buy){
            int b = -prices[idx] + f(idx+1,0,prices,dp,n);
            int nb = f(idx+1,1,prices,dp,n);
            profit = max(b,nb);
        }
        else{
            int s = +prices[idx] + f(idx+1,1,prices,dp,n);
            int ns = f(idx+1,0,prices,dp,n);
            profit = max(s,ns);
        }
        return dp[idx][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        dp[n][0] = dp[n][1] = 0; //base cases

        for(int idx = n-1;idx>=0;idx--){
            for(int buy = 0;buy<=1;buy++){
                int profit = 0;
                if(buy){
                    int b = -prices[idx] + dp[idx+1][0];
                    int nb = dp[idx+1][1];
                    profit = max(b,nb);
                }
                else{
                    int s = +prices[idx] + dp[idx+1][1];
                    int ns = dp[idx+1][0];
                    profit = max(s,ns);
                }
                dp[idx][buy] = profit;
            }
        }
        return dp[0][1];
    }
};