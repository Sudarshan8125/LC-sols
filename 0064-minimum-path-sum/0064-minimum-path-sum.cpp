class Solution {
public:
    int f(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (r < 0 || c < 0)
            return 1e9;
        if (r == 0 && c == 0)
            return grid[0][0];

        if (dp[r][c] != -1)
            return dp[r][c];
        // exp all possible options
        int up = grid[r][c] + f(r - 1, c, grid, dp);
        int left = grid[r][c] + f(r, c - 1, grid, dp);

        // min of all op would be the answer
        return dp[r][c] = min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // convert to tabulation
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (r == 0 && c == 0) {
                    dp[r][c] = grid[r][c];
                    continue;
                }

                int up = 1e9;
                int left = 1e9;
                if(r>0) up = grid[r][c] + f(r - 1, c, grid, dp);
                if(c>0) left = grid[r][c] + f(r, c - 1, grid, dp);

                // min of all op would be the answer
                dp[r][c] = min(up, left);
            }
        }

        return dp[m-1][n-1];
    }
};