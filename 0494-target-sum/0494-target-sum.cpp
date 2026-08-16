class Solution {
public:    
    // int f(int idx,int tar,vector<int>& arr,vector<vector<int>>& dp){
        
    //     if(idx == 0){
    //         if(tar == 0 && arr[0] == 0) return 2;
    //         if(tar == 0) return 1;
    //         if(arr[0] == tar) return 1;
    //         return 0;
    //     }
        
    //     if(dp[idx][tar] != -1) return dp[idx][tar];
        
    //     int nottake = f(idx-1,tar,arr,dp);
    //     int take = 0;
    //         if(tar >= arr[idx]) take = f(idx-1,tar-arr[idx],arr,dp);
            
    //     return dp[idx][tar] = take + nottake;
    // }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int tsum = accumulate(nums.begin(),nums.end(),0);
        if((tsum-target)%2 != 0 || tsum-target<0) return 0;

        int sum = (tsum-target)/2;
        vector<int> prev(sum+1,0);

        if(nums[0] == 0){
            prev[0] = 2; //both take and nottake can be executed
        }
        else prev[0] = 1; //only not take can be executed
        if(nums[0]!=0 && nums[0]<=sum) prev[nums[0]] = 1;//take case for above //if in bound


        for(int idx=1;idx<n;idx++){
            for(int tar=sum;tar>=0;tar--){
                int nottake = prev[tar];
                int take = 0;
                if(tar >= nums[idx]) take = prev[tar-nums[idx]];
            
                prev[tar] = take + nottake;
            }
        }
        return prev[sum];
    }
};