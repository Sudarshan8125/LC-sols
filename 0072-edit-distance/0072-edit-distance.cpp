class Solution {
public:
    int f(int i1,int i2,string& word1,string& word2,vector<vector<int>>& dp){
        if(i1<0 && i2<0) return 0;
        if(i1<0) return i2+1;
        if(i2<0) return i1+1;

        if(dp[i1][i2]!=-1) return dp[i1][i2];

        if(word1[i1] == word2[i2]) return dp[i1][i2] = f(i1-1,i2-1,word1,word2,dp);

        int add = 1 + f(i1,i2-1,word1,word2,dp); 
        int rem = 1 + f(i1-1,i2,word1,word2,dp);   //word1 ka part remove
        int rep = 1 + f(i1-1,i2-1,word1,word2,dp);

        return dp[i1][i2] = min({add,rep,rem});
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,word1,word2,dp);
    }
};