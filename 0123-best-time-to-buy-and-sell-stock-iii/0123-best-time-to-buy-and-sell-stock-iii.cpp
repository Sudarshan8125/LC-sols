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
        vector<int> curr(5, 0);
        vector<int> next(5, 0);
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int buy = 3; buy >= 0; buy--) {
                if (buy % 2 == 0) {
                    int b = -prices[idx] + next[buy + 1];
                    int nb = next[buy];
                    curr[buy] = max(b, nb);
                } else {
                    int s = +prices[idx] + next[buy + 1];
                    int ns = next[buy];
                    curr[buy] = max(s, ns);
                }
            }
            next = curr;
        }
        return curr[0]; // with buy permission
    }
};