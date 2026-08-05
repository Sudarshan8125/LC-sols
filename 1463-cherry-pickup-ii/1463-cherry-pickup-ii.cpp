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
        
        vector<vector<int>> front(m,vector<int>(m,0));
        vector<vector<int>> curr(m,vector<int>(m,0));
        //declare base cases
        for(int c1=0;c1<m;c1++){
            for(int c2=0;c2<m;c2++){
                if(c1==c2) front[c1][c2] = grid[n-1][c1];
                else front[c1][c2] = grid[n-1][c1] + grid[n-1][c2];
            }
        }
        //loops
        for(int r=n-2;r>=0;r--){
            for(int c1=0;c1<m;c1++){ //these 2 make cases for n-2th row both at 00 11 01 etc
                for(int c2=0;c2<m;c2++){

                    int maxi = INT_MIN; //har n-2th row ke case ke liye // explore nichli row wale options
                    for(int i=-1; i<=1; i++){
                        for(int j=-1; j<=1; j++){
                            int value = 0;
                            if(c1==c2) value = grid[r][c1];
                            else value = grid[r][c1] + grid[r][c2];
                            if(c1 + i >= 0 && c1 + i < m && c2 + j >= 0 && c2 + j < m) {
                                value += front[c1+i][c2+j];
                            } else {
                                value += -1e9; // Fixed: Add penalty for illegal out-of-bounds moves
                            }
                            maxi = max(maxi,value);
                        }
                    }
                    
                    curr[c1][c2] = maxi;  //assign the max poss value for that case
                }
            }
            front = curr;
        }


        return curr[0][m-1];
    }
};