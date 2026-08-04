class Solution {
public:
    int f(int r,int c,vector<vector<int>>& dp){
        if(r<0 || c<0) return 0;
        if(r == 0 || c == 0){
            return 1;
        }

        if(dp[r][c]!=-1) return dp[r][c]; //since fxn return ways for every junction/index

        //do all possible stuffs with these indexes
        int u = f(r-1,c,dp);
        int l = f(r,c-1,dp);

        return dp[r][c] = u+l; // return this since they are seperate ways and hence addition 
    }

    int uniquePaths(int m, int n) {
        //count all possible ways that lead to n-1,m-1

        vector<vector<int>> dp(n,vector(m,-1));
        return f(n-1,m-1,dp);    
    }
};