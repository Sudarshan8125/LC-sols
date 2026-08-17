class Solution {
public:
    int f(int idx, int buy, vector<int>& prices, int n,int txend,vector<vector<int>>& dp) {
        if (idx == n || buy == txend) {
            return 0;
        }

        if (dp[idx][buy] != -1)
            return dp[idx][buy];

        if (buy % 2 == 0) {
            int b = -prices[idx] + f(idx + 1, buy + 1, prices, n, txend, dp);
            int nb = f(idx + 1, buy, prices, n, txend, dp);
            return dp[idx][buy] = max(b, nb);
        } else {
            int s = +prices[idx] + f(idx + 1, buy + 1, prices, n, txend, dp);
            int ns = f(idx + 1, buy, prices, n, txend, dp);
            return dp[idx][buy] = max(s, ns);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
         //try out all ways
        int n = prices.size();

        vector<vector<int>> dp(n+1,vector<int>(2*k+1,-1)); 
        return f(0,0,prices,n,2*k+1,dp); 
    }
};