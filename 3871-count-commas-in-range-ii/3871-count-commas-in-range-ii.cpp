class Solution {
public:
    long long countCommas(long long n) {
        long long commas = 0;
        
        // Loop through each comma placeholder boundary: 10^3, 10^6, 10^9, 10^12, 10^15
        for (long long i = 1000; i <= n; i *= 1000) {
            commas += (n - i + 1);
            
            // Prevent integer overflow on 'i *= 1000' if n goes up to 1e15 or higher
            if (i > LLONG_MAX / 1000) break; 
        }
        
        return commas;
    }
};
