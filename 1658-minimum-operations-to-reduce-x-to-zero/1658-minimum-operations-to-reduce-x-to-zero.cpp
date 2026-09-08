class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int t_sum = accumulate(nums.begin(),nums.end(),0);
        if(x>t_sum) return -1;
        int goal = t_sum - x; //min len for this sum

        int l = 0,r = 0;
        int maxlen = -1;
        int sum = 0;
        while(r<n){
            sum+=nums[r];
            while(sum>goal){
                sum -= nums[l];
                l++;
            }
            if(goal == sum){
                int len = r-l+1;
                maxlen = max(len,maxlen);
            }
            r++;
        }
        return maxlen == -1 ? -1:n-maxlen;
    }
};