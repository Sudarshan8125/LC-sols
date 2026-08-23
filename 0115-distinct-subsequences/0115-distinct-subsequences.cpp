class Solution {
public:
    // int f(int idx1,int idx2,string& s,string& t,vector<vector<int>>& dp){
    //     if(idx2 == 0) return 1; //allchar matched
    //     if(idx1 == 0) return 0;

    //     if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        
    //     if(s[idx1-1] == t[idx2-1]){
    //         int l = f(idx1-1,idx2-1,s,t,dp);
    //         int r = f(idx1-1,idx2,s,t,dp);
            
    //         return dp[idx1][idx2] = l+r;
    //     }

    //     return dp[idx1][idx2] = f(idx1-1,idx2,s,t,dp);
    // }
    
    int numDistinct(string s, string t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = s.size();
        int m = t.size();

        string subs = "";
        vector<unsigned long long> prev(m+1,0);

        //using 1 based
        prev[0] = 1;

        for(int idx1=1;idx1<=n;idx1++){
            for(int idx2=m;idx2>0;idx2--){

                if(s[idx1-1] == t[idx2-1]){              
                    prev[idx2] = prev[idx2-1] + prev[idx2];
                }
                else prev[idx2] = prev[idx2];      

            }
        }
        return prev[m];
    }
};