class Solution {
public:
    bool check(const string &s){
        string rev = s;
        reverse(rev.begin(),rev.end());

        return s == rev;
    }

    bool validPalindrome(string s) {
        int l = 0;
        int n = s.size();
        int r = n-1;

        while(l<=r){
            if(s[l]!=s[r]){
                bool f = check(s.substr(l,r-l));       // remove s[r]
                bool sec = check(s.substr(l+1,r-l));  // remove s[l]

                if(sec || f) return true;
                else return false;
            }
            l++;
            r--;
        }

        return true;
    }
};