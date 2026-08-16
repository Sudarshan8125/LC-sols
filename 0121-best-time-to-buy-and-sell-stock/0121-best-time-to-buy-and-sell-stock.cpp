class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n=nums.size();
        int x=nums[0],prof=0;
        for(int i=1;i<n;i++){
            prof=max(prof,nums[i]-x);
            x=min(nums[i],x);
        }
        return prof;
    }
};