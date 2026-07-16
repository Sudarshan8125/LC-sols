class Solution {
public:
    int gcd(int a, int b) {
        if (a == 0) {
            return b;
        } else if (a <= b) {
            return gcd(b % a, a);
        }
        return gcd(a % b, b);
    }
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,0);
        int max = nums[0];

        for(int i=0;i<n;i++){
            if(nums[i]>max) max = nums[i];
            prefix[i] = gcd(max,nums[i]);
        }
        sort(prefix.begin(),prefix.end());
        int l=0,r=n-1;
        long long sum = 0;
        while(l<r){
            sum += gcd(prefix[l++],prefix[r--]);
        }
        return sum;
    }
};