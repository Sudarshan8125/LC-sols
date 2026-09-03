class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l=0,r=0;
        int maxlen=0;
        int maxfreq=0;
        // unordered_map<char,int> mpp;

        // while(r<n){
        //     mpp[s[r]]++;
        //     maxfreq = max(maxfreq,mpp[s[r]]);
        //     int len = r-l+1;
        //     if(len-maxfreq>k){
        //         mpp[s[l]]--;
        //         l++;
        //     }
        //     maxlen = max(maxlen,r-l+1);
        //     r++;
        // }

        //USING HASHMAPS//
        int hash[26] = {0};
        while(r<n){

            hash[s[r]-'A']++;
            maxfreq = max(maxfreq,hash[s[r]-'A']);
            int len = r-l+1;
            if(len-maxfreq>k){
                hash[s[l]-'A']--;
                l++;
            }

            maxlen = max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};