class Solution {
public:
    int f(int r,int c,vector<vector<int>>& mat,vector<vector<int>>& dp){
        int n = mat.size();
        if(c<0 || c>=n) return 1e9;
        if(r==0) return mat[0][c];

        if(dp[r][c]!=-1e9) return dp[r][c];

        int up = f(r-1,c,mat,dp);
        int left = f(r-1,c-1,mat,dp);
        int right = f(r-1,c+1,mat,dp);

        return dp[r][c] = mat[r][c] + min({up,right,left});

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1e9)); // keep a val that doesnt gets mixed

        int mini = 1e9;
        for(int i=n-1;i>=0;i--){ //for the entire last row
            int s = f(n-1,i,matrix,dp);
            mini = min(mini,s);
        }
        return mini;
    }
};