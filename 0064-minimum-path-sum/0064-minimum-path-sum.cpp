class Solution {
public:
    int f(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(r<0 || c<0) return INT_MAX;
        if(r==0 && c==0) return grid[0][0];
        if(dp[r][c]!=-1) return dp[r][c];
        //do all stuffs
        int up = grid[r][c] + f(r-1,c,grid,dp);
        int left = grid[r][c] + f(r,c-1,grid,dp);

        return dp[r][c] = min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        //conversion to tabulation
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0){
                    dp[i][j] = grid[i][j];
                    continue;
                }

                int up = INT_MAX;
                int left = INT_MAX;

                if(i>0) up = grid[i][j] + dp[i-1][j];
                if(j>0) left = grid[i][j] + dp[i][j-1];

                dp[i][j] = min(up,left);
            }
        }

        return dp[n-1][m-1];
    }
};