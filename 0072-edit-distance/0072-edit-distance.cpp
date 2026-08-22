class Solution {
public:
    // int f(int i1,int i2,string& word1,string& word2,vector<vector<int>>& dp){
    //     if(i1 == 0 && i2 == 0) return 0;
    //     if(i1 == 0) return i2;
    //     if(i2 == 0) return i1;

    //     if(dp[i1][i2]!=-1) return dp[i1][i2];

    //     if(word1[i1-1] == word2[i2-1]) return dp[i1][i2] = f(i1-1,i2-1,word1,word2,dp);

    //     int add = 1 + f(i1,i2-1,word1,word2,dp); 
    //     int rem = 1 + f(i1-1,i2,word1,word2,dp);   //word1 ka part remove
    //     int rep = 1 + f(i1-1,i2-1,word1,word2,dp);

    //     return dp[i1][i2] = min({add,rep,rem});
    // }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        //use offset +1 evry where => do 1 based indexing for dp table
        for(int i = 0; i <= n; i++){
            dp[i][0] = i;
        }
    
        for(int j = 0; j <= m; j++){
            dp[0][j] = j;
        }

        for(int i1=1; i1<=n; i1++){
            for(int i2=1; i2<=m; i2++){
                if(word1[i1-1] == word2[i2-1]) dp[i1][i2] = dp[i1-1][i2-1];

                else{
                    int add = 1 + dp[i1][i2-1];
                    int rem = 1 + dp[i1-1][i2];   //word1 ka part remove
                    int rep = 1 + dp[i1-1][i2-1];
                    dp[i1][i2] = min({add,rep,rem});
                }
            }
        }
        
        return dp[n][m];
    }
};