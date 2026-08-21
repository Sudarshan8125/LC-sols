class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();

        string rev = s;
        reverse(rev.begin(),rev.end());

        vector<int> prev(n+1,0);
        vector<int> curr(n+1,0);

        for(int i1 = 1; i1<=n; i1++){
            for(int i2 = 1; i2<=n; i2++){
                
                if(s[i1-1] == rev[i2-1]){
                    curr[i2] = prev[i2-1] + 1;
                }
                else{
                    curr[i2] = max(prev[i2],curr[i2-1]);
                }
            }
            prev = curr;
        }
        return n - prev[n];
    }
};