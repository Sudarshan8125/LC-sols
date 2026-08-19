class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i=0;
        int sign = 1;
        long long res = 0;
        while(i<n && s[i]==' ') i++;

        if(i<n && (s[i]=='+' || s[i]=='-')){
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while(i<n && '0'<=s[i] && s[i]<='9'){
            res = res * 10 + (s[i] - '0');
            
            if (sign == 1 && res > INT_MAX) return INT_MAX;
            if (sign == -1 && -res < INT_MIN) return INT_MIN;
            
            i++;
        }
        
        return sign*res;
    }
};