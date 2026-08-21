class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i1 = 1; i1<=n; i1++){
            for(int i2 = 1; i2<=m; i2++){
                
                if(str1[i1-1] == str2[i2-1]){
                    dp[i1][i2] = dp[i1-1][i2-1] + 1;
                }
                else{
                    dp[i1][i2] = max(dp[i1-1][i2],dp[i1][i2-1]);
                }
            }
        }
        int len = dp[n][m];
        int index = n+m - len -1;
        string res(n + m - len, '$');
        

        int i = n, j = m;

        while(i>0 && j>0){
            if(str1[i-1] == str2[j-1]){
                res[index] = str1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                res[index] = str1[i-1]; 
                i--; 
            }  
            else{
                res[index] = str2[j-1];
                j--;
            } 
            index--;
        }

        while(i>0){
            res[index] = str1[i-1];
            i--;index--;
        }
        while(j>0){
            res[index] = str2[j-1];
            j--;index--;
        }

        return res;
    }
};