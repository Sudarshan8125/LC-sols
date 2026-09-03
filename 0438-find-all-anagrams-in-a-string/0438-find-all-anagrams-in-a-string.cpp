class Solution {
public:
    bool isAnagram(vector<int>& freq){
        for(auto it:freq){
            if(it!=0) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        //freq match =>anagram
        int n = s.size();
        int k = p.size();
        vector<int> ans;
        if(k>n) return ans;

        int l = 0;
        int r = 0;

        vector<int> freq(26,0);
        for(auto ch:p) freq[ch-'a']++;

        while(r<n){
            freq[s[r]-'a']--;

            if(r-l+1 == k){
                if(isAnagram(freq)){
                    ans.push_back(l);
                }

                freq[s[l]-'a']++;
                l++;
            }
            r++;
        }

        return ans;
    }
};