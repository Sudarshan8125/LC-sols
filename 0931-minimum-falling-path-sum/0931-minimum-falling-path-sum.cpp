class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n,0); // keep a val that doesnt gets mixed

        for(int c=0;c<n;c++){
            prev[c] = matrix[0][c];
        }

        for(int r=1;r<n;r++){
            vector<int> curr(n,0);
            for(int c=0;c<n;c++){

                int left = 1e9, right = 1e9;

                int up = prev[c];
                if(c>0) left = prev[c-1];
                if(c<n-1) right = prev[c+1];
                curr[c] = matrix[r][c] + min({up,right,left});                
            }
            prev = curr;
        }

        int mini = 1e9;
        for(int c=n-1;c>=0;c--){ //for the entire last row
            int s = prev[c];
            mini = min(mini,s);
        }
        return mini;
    }
};