class Solution {
public:
    // int f(int r1,int c1,int c2,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
    //     int r2 = r1 + c1 - c2;
    //     //moves ->left/up..
    //     // 1. Boundary & Blocked Path Checks (Use -1e9 instead of -1)
    //     if (r1 < 0 || c1 < 0 || r2 < 0 || c2 < 0) return -1e9;
    //     if (grid[r1][c1] == -1 || grid[r2][c2] == -1) return -1e9;
    //     if(r1==0 && c1==0) return grid[0][0];

    //     if(dp[r1][c1][c2]!=-1) return dp[r1][c1][c2];
    //     //explore all options
    //     int pth1 = f(r1-1,c1,c2,grid,dp);
    //     int pth2 = f(r1-1,c1,c2-1,grid,dp);
    //     int pth3 = f(r1,c1-1,c2,grid,dp);
    //     int pth4 = f(r1,c1-1,c2-1,grid,dp);

            // FIND THE BEST PATH FIRST
//          int max_path = max({pth1, pth2, pth3, pth4});
        
            // BUG FIX: If all paths ahead are dead-ends, this state is a dead-end!
//          if (max_path == -1e9) return dp[r1][c1][c2] = -1e9;

    //     int cherries = 0;
    //     if(c1!=c2) cherries = grid[r1][c1] + grid[r2][c2];
    //     else cherries = grid[r1][c1];

    //     return dp[r1][c1][c2] = cherries + maxi;
    // }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
                //letting one go first and then the other would be greedy
                //3 state sol both would reach 0,0 together
        if(grid[0][0] == -1 || grid[n-1][n-1] == -1) return 0;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n,-1))); //this defines a list of 2d matrices

        dp[0][0][0] = grid[0][0]; 

        for(int r1=0;r1<n;r1++){
            for(int c1=0;c1<n;c1++){
                for(int c2=0;c2<n;c2++){
                        int r2 = r1 + c1 - c2;
                    if(r2<0 || r2>=n) continue;
                    if(r1==0 && c1==0 && c2==0) continue;
                    if(grid[r1][c1]==-1 || grid[r2][c2]==-1){
                        dp[r1][c1][c2] = -1;
                        continue;
                    }
                    
                     int pth1=-1, pth2=-1, pth3=-1, pth4=-1;  

                    if(r1>0) pth1 = dp[r1-1][c1][c2];
                    if(r1>0 && c2>0) pth2 = dp[r1-1][c1][c2-1];
                    if(c1>0) pth3 = dp[r1][c1-1][c2];
                    if(c1>0 && c2>0) pth4 =dp[r1][c1-1][c2-1];

                    int max_path = max({pth1, pth2, pth3, pth4});

                    if (max_path == -1) continue;   
                    
                    int cherries = 0;
                    if(c1!=c2) cherries = grid[r1][c1] + grid[r2][c2];
                    else cherries = grid[r1][c1];

                    dp[r1][c1][c2] = cherries + max_path;
                }
            }
        }
        
     
        return max(0,dp[n-1][n-1][n-1]);
    }
};