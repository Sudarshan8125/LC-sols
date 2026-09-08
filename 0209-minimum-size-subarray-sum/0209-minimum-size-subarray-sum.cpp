class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int sum = 0;
        int minlen = 1e9;
        while(r<n){
            sum += nums[r];
            while(sum>=target){
                minlen = min(minlen,r-l+1);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return minlen == 1e9? 0:minlen;
    }
};