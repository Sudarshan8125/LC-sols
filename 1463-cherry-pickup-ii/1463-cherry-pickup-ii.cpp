class Solution {
public:

    int f(int r,int c1,int c2,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        int n = grid.size();
        int m = grid[0].size();
        //write base cases
        if(c1<0 || c1>=m || c2<0 || c2>=m) return -1e9; //1e9 for max case.. -1e9 here so it never pick
        if(r==n-1) return c1!=c2 ? grid[r][c1] + grid[r][c2] : grid[r][c1];

        if(dp[r][c1][c2] != -1) return dp[r][c1][c2]; //if state was prev encountered
        //do all stuffs
        int maxi = INT_MIN;
        for(int i=-1; i<=1; i++){
            for(int j=-1; j<=1; j++){
                int value = 0;
                if(c1==c2) value = grid[r][c1];
                else value = grid[r][c1] + grid[r][c2];
                value += f(r+1,c1+i,c2+j,grid,dp);
                maxi = max(maxi,value);
            }
        }
        
       return dp[r][c1][c2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return f(0,0,m-1,grid,dp);
    }
};