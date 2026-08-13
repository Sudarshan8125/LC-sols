class Solution {
public:
    int f(int r,int c1,int c2,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        int n = grid.size();
        int m = grid[0].size();
        //base cases
        if(c1<0 || c1>=m || c2<0 || c2>=m) return -1;
        if(r==n-1){
            if(c1!=c2) return grid[n-1][c1] + grid[n-1][c2];  
            else return grid[n-1][c1];
        }

        if(dp[r][c1][c2]!=-1) return dp[r][c1][c2];

        int maxi = -1;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int x = c1+i;
                int y = c2+j;
                if(x>=0 && x<m && y>=0 && y<m){ //for all valid next states
                    int value = 0;
                    if(c1!=c2) value+=grid[r][c1] + grid[r][c2];
                    else value += grid[r][c1];
                    value += f(r+1,x,y,grid,dp);
                    maxi = max(maxi,value);
                }
            }
        }
        return dp[r][c1][c2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return f(0,0,m-1,grid,dp); //passed up the fixed start points
    }
};