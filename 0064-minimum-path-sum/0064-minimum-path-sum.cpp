class Solution {
public:
    int f(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(r<0 || c<0) return INT_MAX;
        if(r==0 && c==0) return grid[0][0];
        if(dp[r][c]!=-1) return dp[r][c];
        //do all stuffs
        int up = f(r-1,c,grid,dp);
        int left = f(r,c-1,grid,dp);

        return dp[r][c] = grid[r][c] + min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));

        return f(n-1,m-1,grid,dp);
    }
};