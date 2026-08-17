class Solution {
public:
    // int f(int idx,int buy,vector<int>& prices,vector<vector<int>>& dp,int n,int fee){
    //     if(idx==n) return 0;

    //     if(dp[idx][buy]!=-1) return dp[idx][buy];
    //     int profit = 0;
    //     if(buy){
    //         int b = -prices[idx] + f(idx+1,0,prices,dp,n,fee);
    //         int nb = f(idx+1,1,prices,dp,n,fee);
    //         profit = max(b,nb);
    //     }
    //     else{
    //         int s = +prices[idx] - fee + f(idx+1,1,prices,dp,n,fee);
    //         int ns = f(idx+1,0,prices,dp,n,fee);
    //         profit = max(s,ns);
    //     }
    //     return dp[idx][buy] = profit;
    // }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));

        for(int idx = n-1;idx>=0;idx--){         
            dp[idx][1] = max( -prices[idx] + dp[idx+1][0], dp[idx+1][1]);           
            dp[idx][0] = max( +prices[idx] - fee + dp[idx+1][1], dp[idx+1][0]);
        }
        
        return dp[0][1];
    }
};