class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        // SLIDING WINDOW SOL //
        unordered_map<char,int> freq; // for char and its index
        int maxlen=0;
        int l = 0;

        for(int r=0;r<n;r++){
           
            if(freq.find(s[r])!=freq.end() && freq[s[r]]>=l){ //bc we check dup occ in this part window
                l = freq[s[r]] + 1;
            }
            int len = r-l+1;
            maxlen = max(len,maxlen);
            freq[s[r]] = r;
        }

        
        return maxlen;
    }
};