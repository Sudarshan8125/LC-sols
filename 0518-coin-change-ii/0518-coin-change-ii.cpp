class Solution {
public:
    int f(int idx, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (idx == 0) {
            if (amount % coins[0] == 0)
                return 1;
            return 0;
        }

        if (dp[idx][amount] != -1)
            return dp[idx][amount];
        // pick
        int pick = 0;
        if (amount >= coins[idx])
            pick = f(idx, amount - coins[idx], coins, dp);

        // not pick
        int notpick = f(idx - 1, amount, coins, dp);

        return dp[idx][amount] = pick + notpick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(amount + 1, 0); // size cant ever be -1.

        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0)
                prev[i] = 1; // konse amount ko coins[0] se bna skte hao
        }

        for (int idx = 1; idx < n; idx++) {
            for (int tar = 0; tar <= amount; tar++) {
                long long pick = 0;
                if (tar >= coins[idx])
                    pick = prev[tar - coins[idx]];

                long long notpick = prev[tar];

                prev[tar] = pick + notpick;
            }
        }
        return (int)prev[amount];
    }
};
