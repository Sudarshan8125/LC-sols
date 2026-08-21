class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> prev(m+1,0);
        vector<int> curr(m+1,0);

        for(int i1 = 1; i1<=n; i1++){
            for(int i2 = 1; i2<=m; i2++){
                
                if(word1[i1-1] == word2[i2-1]){
                    curr[i2] = prev[i2-1] + 1;
                }
                else{
                    curr[i2] = max(prev[i2],curr[i2-1]);
                }
            }
            prev = curr;
        }
        return n + m - 2*prev[m]; //max-common => max = del all of 1, add all of 2
    }
};