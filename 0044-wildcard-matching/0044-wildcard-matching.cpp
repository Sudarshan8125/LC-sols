class Solution {
public:
    // bool f(int idx1,int idx2,string& s,string& p,vector<vector<int>>& dp){
    //     //dp sol
    //     if(idx1 == 0 && idx2 == 0) return true; //both completely matches
    //     if(idx2 == 0) return false;
    //     if(idx1 == 0){
    //         for(int i=1;i<=idx2;i++) if(p[i-1]!='*') return false;
    //         return true;
    //     }

    //     if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
    //     //cant leave a character in between
    //     //if(s[idx1] != p[idx2]) return false;
    //     if(s[idx1-1]  == p[idx2-1] || p[idx2-1] == '?') return dp[idx1][idx2] = f(idx1-1,idx2-1,s,p,dp);

    //     if(p[idx2-1] == '*'){
    //         //take in 
    //         bool takein = f(idx1-1,idx2,s,p,dp);
    //         bool nottakein = f(idx1,idx2-1,s,p,dp);

    //         return dp[idx1][idx2] = takein || nottakein;
    //     }

    //     return dp[idx1][idx2] = false; //not match implemented
    // }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<bool> prev(m + 1, false);
        vector<bool> curr(m + 1, false);
        prev[0] = true;

        for (int i = 1; i <= m; i++) {
            if (p[i - 1] == '*') {
                prev[i] = prev[i - 1]; // It depends on whether the prefix was valid!
            } else {
                prev[i] = false; // A non-asterisk character cannot match an empty string
            }
        }
    

        for(int idx1 = 1;idx1<=n;idx1++){
            for(int idx2 = 1;idx2<=m;idx2++){

                if(s[idx1-1]  == p[idx2-1] || p[idx2-1] == '?') curr[idx2] = prev[idx2-1];

                else if(p[idx2-1] == '*'){
                    //take in 
                    bool takein = prev[idx2];
                    bool nottakein = curr[idx2-1];

                    curr[idx2] = takein || nottakein;
                }

                else curr[idx2] = false; //not match implemented
            }
            prev = curr;
        }
        
        // 1 based indexing
        return prev[m];
    }
};