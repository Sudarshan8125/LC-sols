class Solution {
public:
    int MOD = 1e9 + 7;

    int f(int idx,string& s,vector<int>& dp){
        if(idx<0) return 1;

        if (dp[idx] != -1) return dp[idx];
        //find prev position
        int prev = -1;
        for (int i = idx - 1; i >= 0; i--) {
            if (s[i] == s[idx]) {
                prev = i;
                break;
            }
        }


        if(prev == -1){
            return dp[idx] = (2LL * f(idx - 1, s, dp)) % MOD;
        }

        long long total = (2LL * f(idx - 1, s, dp)) % MOD;
        long long duplicates = f(prev - 1, s, dp);

        return dp[idx] = (total - duplicates + MOD) % MOD;
    }
    int distinctSubseqII(string s) {
        int n = s.size();

        vector<int> dp(n,-1);
         return (f(n - 1, s, dp) - 1 + MOD) % MOD;
    }
};