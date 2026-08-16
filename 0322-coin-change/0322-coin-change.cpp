class Solution {
public:
    int f(int idx, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (idx == 0) {
            if (amount % coins[0] == 0)
                return amount / coins[0]; // If divisible, return quotient
            return 1e9;                   // Otherwise impossible
        }

        if (dp[idx][amount] != -1)
            return dp[idx][amount];
        // pick
        int pick = 1e9;
        if (amount >= coins[idx])
            pick = 1 + f(idx, amount - coins[idx], coins, dp);

        // not pick
        int notpick = f(idx - 1, amount, coins, dp);

        return dp[idx][amount] = min(pick, notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1,1e9); // size cant ever be -1.

        for (int T = 0; T <= amount; T++) {
            if (T % coins[0] == 0) prev[T] = T / coins[0];            
        }
    
        for (int idx = 1; idx < n; idx++) {
            for (int T = 0; T <= amount; T++) {
                // pick
                int pick = 1e9;
                if (T >= coins[idx])
                    pick = 1 + prev[T - coins[idx]];

                // not pick
                int notpick = prev[T];

                prev[T] = min(pick, notpick);
            }
        }
        int ans = prev[amount];
        return ans >= 1e9 ? -1 : ans;
    }
};