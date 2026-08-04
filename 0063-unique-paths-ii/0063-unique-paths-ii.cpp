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

        //convert to tabultion
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(obstacleGrid[r][c]){
                    dp[r][c] = 0;
                    continue;
                }
                if(r==0 && c==0){
                    dp[0][0] = 1;
                    continue;
                }
                int up = 0, left = 0;
                if(r>0) up = dp[r-1][c];
                if(c>0) left = dp[r][c-1];

                dp[r][c] = up+left;
            }
        }
        return dp[m-1][n-1];
    }
};