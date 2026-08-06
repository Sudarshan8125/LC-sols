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
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2 == 1) return false;
        
        vector<vector<int>> dp(n,vector<int>(sum/2+1,false));

        //tabulation approach
        for(int i=0;i<n;i++) dp[i][0] = true;
        if(nums[0] <= sum/2) dp[0][nums[0]] = true; //bound safe check behind // 0th row done

        for(int idx = 1; idx<n; idx++){
            for(int target = 1; target <= sum/2 ;target++){
                bool nottake = dp[idx-1][target];
                bool take = false;
                if(target >= nums[idx]) take = dp[idx-1][target-nums[idx]];

                dp[idx][target] = nottake || take; //can we reach the val of sum/2 in the range idx->0.
            }
        }

        return dp[n-1][sum/2]; 
    }
};