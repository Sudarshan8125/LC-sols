class Solution {
public:
    string bin(char ch) {
        int x = ch;
        string res = "";
        while (x > 0) {
            res += (x % 2) + '0';
            x /= 2;
        }
        while (res.size() < 8) res += '0';
        reverse(res.begin(), res.end());
        return res;
    }

    bool isPalindromic(string s) {
        string full = "";
        for (char ch : s) full += bin(ch);

        int l = 0, r = full.size() - 1;
        while (l <= r) {
            if (full[l] != full[r]) return false;
            l++; r--;
        }
        return true;
    }
};