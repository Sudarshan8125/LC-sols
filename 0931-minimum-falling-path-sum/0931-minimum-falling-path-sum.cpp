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
        //tabulation approach
        vector<vector<int>> dp(n, vector<int>(n, -1e9));

        //write the base case
        for(int j=0;j<n;j++) dp[0][j] = matrix[0][j];
        //rec n-1->0 thefo tab 0->n-1
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                
                int up = dp[i-1][j];
                int left = INT_MAX,right = INT_MAX;
                if(j>=1) left = dp[i-1][j-1];
                if(j+1<n) right = dp[i-1][j+1];

                dp[i][j] = matrix[i][j] + min({up,left,right});
            }
        }
        
        for(int j=0;j<n;j++){ //check for the min in last row
            mini = min(mini,dp[n-1][j]);
        }

        return mini;
    }
};