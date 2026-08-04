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

        vector<int> prev(n,0);

        //convert to tabultion
        //optimizing space
        for(int r=0;r<m;r++){
            vector<int> temp(n,0);
            for(int c=0;c<n;c++){
                if(obstacleGrid[r][c]){
                    temp[c] = 0;
                    continue;
                }
                if(r==0 && c==0){
                    temp[0] = 1;
                    continue;
                }
                int up = 0, left = 0;
                if(r>0) up = prev[c];
                if(c>0) left = temp[c-1];

                temp[c] = up+left;
            }
            prev = temp;
        }
        return prev[n-1];
    }
};