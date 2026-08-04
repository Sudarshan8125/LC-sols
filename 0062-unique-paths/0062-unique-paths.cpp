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
        //space optimized
        vector<int> prev(n,0);
        //dp[0][0] = 1; //from start to start only one way if it was the case
         
        for(int r=0;r<m;r++){
            vector<int> temp(n,0);
            for(int c=0;c<n;c++){

                if(r==0 && c==0){
                    temp[0] = 1;
                    continue;
                }
                int up = 0,left = 0;

                if(r>0) up = prev[c];
                if(c>0) left = temp[c-1];

                temp[c] = up+left;
            }
            prev = temp;
        }
        //now tabulate this sol  
        return prev[n-1];
    }
};