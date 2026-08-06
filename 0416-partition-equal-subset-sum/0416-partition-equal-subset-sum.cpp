class Solution {
public:

    bool f(int idx,int target,vector<int>& nums,vector<vector<int>>& dp){

        //write base cases
        if(target == 0) return true;
        if(idx == 0) return nums[0] == target;

        if(dp[idx][target]!=-1) return dp[idx][target];

        //do all possibolities
        bool nottake = f(idx-1,target,nums,dp);
        bool take = false;
            if(target >= nums[idx]) take = f(idx-1,target-nums[idx],nums,dp);

        return dp[idx][target] = nottake || take; //can we reach the val of sum/2 in the range idx->0.
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        //for partitioning find subset with sum = arrsum/2;
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2 == 1) return false;
        
        vector<vector<int>> dp(n,vector<int>(sum/2+1,-1));
        return f(n-1,sum/2,nums,dp); 
    }
};