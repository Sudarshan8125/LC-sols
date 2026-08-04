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
        
        //conversion to tabulation
        //space opti
        vector<int> prev(m,0);

        for(int i=0;i<n;i++){
            vector<int> temp(m,0);
            for(int j=0;j<m;j++){
                if(i==0 && j==0){
                    temp[j] = grid[i][j];
                    continue;
                }

                int up = INT_MAX;
                int left = INT_MAX;

                if(i>0) up = grid[i][j] + prev[j];
                if(j>0) left = grid[i][j] + temp[j-1];

                temp[j] = min(up,left); //no return cause we storing states
            }
            prev = temp;
        }

        return prev[m-1];
    }
};