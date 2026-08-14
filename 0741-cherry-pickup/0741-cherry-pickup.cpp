class Solution {
public:
    int f(int r1,int c1,int c2,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        int r2 = r1 + c1 - c2;
        //moves ->left/up..
        // 1. Boundary & Blocked Path Checks (Use -1e9 instead of -1)
        if (r1 < 0 || c1 < 0 || r2 < 0 || c2 < 0) return -1e9;
        if (grid[r1][c1] == -1 || grid[r2][c2] == -1) return -1e9;
        if(r1==0 && c1==0) return grid[0][0];

        if(dp[r1][c1][c2]!=-1) return dp[r1][c1][c2];
        //explore all options
        int pth1 = f(r1-1,c1,c2,grid,dp);
        int pth2 = f(r1-1,c1,c2-1,grid,dp);
        int pth3 = f(r1,c1-1,c2,grid,dp);
        int pth4 = f(r1,c1-1,c2-1,grid,dp);

        int cherries = 0;
        if(c1!=c2) cherries = grid[r1][c1] + grid[r2][c2];
        else cherries = grid[r1][c1];


        int maxi = -1e9;
        maxi = cherries + max({maxi,pth1,pth2,pth3,pth4});
        return dp[r1][c1][c2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
                //letting one go first and then the other would be greedy
                //3 state sol both would reach 0,0 together
        if(grid[0][0] == -1 || grid[n-1][n-1] == -1) return 0;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n,-1))); //this defines a list of 2d matrices
        int result = f(n - 1, n - 1, n - 1, grid, dp);
        
        // If result is negative, it means no valid path existed
        return max(0, result);
    }
};