class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        //space opti
        vector<int> prev(n, 0);
        vector<int> curr(n, 0);

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (r == 0 && c == 0) {
                    curr[c] = grid[r][c];
                    continue;
                }

                int up = 1e9;
                int left = 1e9;
                if(r>0) up = grid[r][c] + prev[c];
                if(c>0) left = grid[r][c] + curr[c - 1];

                // min of all op would be the answer
                curr[c] = min(up, left);
            }
            prev = curr;
        }

        return prev[n-1];
    }
};