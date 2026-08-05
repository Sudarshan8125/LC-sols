class Solution {
public:

    int f(int row,int col,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        //base cases
        int n = matrix.size();
        if (col < 0 || col >= n) return 1e9; 
        if(row == 0) return matrix[row][col];

        if (dp[row][col] != -1e9) return dp[row][col];
        //do all stuffs
        int up = f(row-1,col,matrix,dp);
        int left = f(row-1,col-1,matrix,dp);
        int right = f(row-1,col+1,matrix,dp);

        return dp[row][col] = matrix[row][col] + min({up,left,right});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = INT_MAX;
        //case of overlapping subproblem
        vector<vector<int>> dp(n, vector<int>(n, -1e9));
        for(int i=n-1;i>=0;i--) mini = min(mini,f(n-1,i,matrix,dp)); //row,col
        return mini;
    }
};