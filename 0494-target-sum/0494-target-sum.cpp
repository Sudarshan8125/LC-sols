class Solution {
public:
    int f(int idx,int offset,int target,int sum,vector<int>& nums,vector<vector<int>>& dp){
        if(idx==0){
            if (nums[idx] == 0 && sum == target) return 2;
            if(sum == target-nums[idx] || sum == target+nums[idx]) return 1;
            return 0;
        }

        if(dp[idx][sum + offset]!=-1e9) return dp[idx][sum+offset];
        //nottake
        int p = f(idx-1,offset,target,sum + nums[idx],nums,dp);

        //take
        int n = f(idx-1,offset,target,sum - nums[idx],nums,dp);

        return dp[idx][offset+sum] = p+n;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        //need to try alll ways 
        //pick=> +
        //notpick=> -
        int tsum = accumulate(nums.begin(),nums.end(),0);

        vector<vector<int>> dp(n,vector<int>(2*tsum+1,-1e9));
        return f(n-1,tsum,target,0,nums,dp);
    }
};