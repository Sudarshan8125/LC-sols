class Solution {
public:
//     int f(int idx, int buy, vector<int>& prices, int n,
//           vector<vector<int>>& dp) {
//         if (idx == n || buy == 4) {
//             return 0;
//         }

//         if (dp[idx][buy] != -1)
//             return dp[idx][buy];

//         if (buy % 2 == 0) {
//             int b = -prices[idx] + f(idx + 1, buy + 1, prices, n, dp);
//             int nb = f(idx + 1, buy, prices, n, dp);
//             return dp[idx][buy] = max(b, nb);
//         } else {
//             int s = +prices[idx] + f(idx + 1, buy + 1, prices, n, dp);
//             int ns = f(idx + 1, buy, prices, n, dp);
//             return dp[idx][buy] = max(s, ns);
//         }
//     }
    int maxProfit(vector<int>& prices) {
        // try out all ways
        int n = prices.size();
        // even b buy
        // odd b sell
        vector<vector<int>> dp(n + 1, vector<int>(5, 0));
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int buy = 3; buy >= 0; buy--) {
                if (buy % 2 == 0) {
                    int b = -prices[idx] + dp[idx + 1][buy + 1];
                    int nb = dp[idx + 1][buy];
                    dp[idx][buy] = max(b, nb);
                } else {
                    int s = +prices[idx] + dp[idx + 1][buy + 1];
                    int ns = dp[idx + 1][buy];
                    dp[idx][buy] = max(s, ns);
                }
            }
        }
        return dp[0][0]; // with buy permission
    }
};