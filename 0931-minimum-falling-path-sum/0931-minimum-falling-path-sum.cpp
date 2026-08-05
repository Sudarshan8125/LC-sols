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

        //space opti
        vector<int> prev(n,0);

        //write the base case
        for(int j=0;j<n;j++) prev[j] = matrix[0][j];

        for(int i=1;i<n;i++){
            vector<int> temp(n,0);
            for(int j=0;j<n;j++){
                
                int up = prev[j];
                int left = INT_MAX,right = INT_MAX;
                if(j>=1) left = prev[j-1];
                if(j+1<n) right = prev[j+1];

                temp[j] = matrix[i][j] + min({up,left,right});
            }
            prev = temp;
        }
        
        for(int j=0;j<n;j++){ //check for the min in last row
            mini = min(mini,prev[j]);
        }

        return mini;
    }
};