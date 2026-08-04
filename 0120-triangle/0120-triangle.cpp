class Solution {
public:
int f(int r,int c,vector<vector<int>>& mat,vector<vector<int>>& dp){
        int n = mat.size();

        if(r == n-1) return mat[r][c];
        if(dp[r][c] != -1e9) return dp[r][c];
        //col overflow case would never happen

        int down = mat[r][c] + f(r+1,c,mat,dp);
        int diag = mat[r][c] + f(r+1,c+1,mat,dp);

        return dp[r][c] = min(down,diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1e9));
        return f(0,0,triangle,dp);
    }
};