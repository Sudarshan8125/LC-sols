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
        vector<int> next(2,0);
        vector<int> curr(2,0);

        for(int idx = n-1;idx>=0;idx--){         
            curr[1] = max( -prices[idx] + next[0], next[1] );           
            curr[0] = max( +prices[idx] - fee + next[1], next[0] );
            next = curr;
        }
        
        return curr[1];
    }
};