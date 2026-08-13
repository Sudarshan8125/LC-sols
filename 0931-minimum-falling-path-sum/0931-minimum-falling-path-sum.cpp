class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1e9)); // keep a val that doesnt gets mixed

        for(int c=0;c<n;c++){
            dp[0][c] = matrix[0][c];
        }

        for(int r=1;r<n;r++){
            for(int c=0;c<n;c++){

                int left = 1e9, right = 1e9;

                int up = dp[r-1][c];
                if(c>0) left = dp[r-1][c-1];
                if(c<n-1) right = dp[r-1][c+1];
                dp[r][c] = matrix[r][c] + min({up,right,left});                
            }
        }

        int mini = 1e9;
        for(int c=n-1;c>=0;c--){ //for the entire last row
            int s = dp[n-1][c];
            mini = min(mini,s);
        }
        return mini;
    }
};