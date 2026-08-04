class Solution {
public:

    int f(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& dp){
        //write base cases
        if(r<0 || c<0) return 0;
        if(grid[r][c] == 1) return 0;//no path through obs

        if(r==0 && c==0) return 1;
        if(dp[r][c]!=-1) return dp[r][c];

        //do all stuffs
        int u = f(r-1,c,grid,dp);
        int l = f(r,c-1,grid,dp);

        return dp[r][c] = u+l;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(m-1,n-1,obstacleGrid,dp); //pass on the starting index nd memo ke liye matrix
    }
};