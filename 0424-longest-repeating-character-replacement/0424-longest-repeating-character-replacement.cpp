class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0;
        int r = 0;
        int mxlen = 0;
        int mxfreq = 0;

        unordered_map<char,int> hash;
        while(r<n){
            hash[s[r]]++;

            mxfreq = max(mxfreq,hash[s[r]]);
            int len = r-l+1;
            if(len-mxfreq > k ){
                hash[s[l]]--;
                if(hash[s[l]] == 0) hash.erase(s[l]);
                l++;
            }
            
            mxlen = max(mxlen,r-l+1);
            r++;
        }
        return mxlen;
    }
};