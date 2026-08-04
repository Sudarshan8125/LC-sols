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
        vector<int> prev(n+1,0);
        
        for(int r=n-1;r>=0;r--){
            vector<int> temp(r+1,0);
            for(int c=r;c>=0;c--){

                int down = triangle[r][c] + prev[c]; //here r+1 means nihce wali row i.e. piche wali
                int diag = triangle[r][c] + prev[c+1];

                temp[c] = min(down,diag);
            }
            prev = temp;
        }
        return prev[0];
    }
};