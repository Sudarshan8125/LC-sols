class Solution {
public:
    int f(int idx, int buy, vector<int>& prices, vector<vector<int>>& dp,
          int n) {
        if (idx == n)
            return 0;

        if (dp[idx][buy] != -1)
            return dp[idx][buy];
        int profit = 0;
        if (buy) {
            int b = -prices[idx] + f(idx + 1, 0, prices, dp, n);
            int nb = f(idx + 1, 1, prices, dp, n);
            profit = max(b, nb);
        } else {
            int s = +prices[idx] + f(idx + 1, 1, prices, dp, n);
            int ns = f(idx + 1, 0, prices, dp, n);
            profit = max(s, ns);
        }
        return dp[idx][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        // Instead of a full 2D array, we only track the next day's results
        int next_buy = 0;  // Corresponds to dp[idx+1][1]
        int next_sell = 0; // Corresponds to dp[idx+1][0]

        for (int idx = n - 1; idx >= 0; idx--) {
            // Calculate current day values using next day variables
            int curr_buy = max(-prices[idx] + next_sell, next_buy);
            int curr_sell = max(prices[idx] + next_buy, next_sell);

            // Slide the window: current day values become the "next" day
            // for the previous loop iteration
            next_buy = curr_buy;
            next_sell = curr_sell;
        }

        return next_buy;
    }
};