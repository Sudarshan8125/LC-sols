class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n=nums.size();
        int x=INT_MAX,prof=0;
        for(int i=0;i<n;i++){
            x=min(nums[i],x);
            prof=max(prof,nums[i]-x);
        }
        return prof;
    }
};