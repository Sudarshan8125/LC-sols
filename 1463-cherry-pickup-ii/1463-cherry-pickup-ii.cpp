class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));

        for(int c1=0;c1<m;c1++){
            for(int c2=0;c2<m;c2++){
                if(c1!=c2) dp[n-1][c1][c2] = grid[n-1][c1] + grid[n-1][c2];
                else dp[n-1][c1][c2] = grid[n-1][c1];
            }
        }

        for(int r=n-2;r>=0;r--){
            for(int c1=0;c1<m;c1++){
                for(int c2=0;c2<m;c2++){

                    int maxi = -1;

                    for(int i=-1;i<=1;i++){
                        for(int j=-1;j<=1;j++){
                            int x = c1+i;
                            int y = c2+j;
                            if(x >= 0 && x < m && y >= 0 && y < m){ 
                                maxi = max(maxi, dp[r+1][x][y]);
                            }
                        }  
                    }            
                    int cherries = (c1 == c2) ? grid[r][c1] : grid[r][c1] + grid[r][c2];     
                    dp[r][c1][c2] = cherries + maxi;               
                }
            }
        }
        return dp[0][0][m-1]; //passed up the fixed start points
    }
};