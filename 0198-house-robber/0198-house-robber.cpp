class Solution {
public:

    int f(int idx,vector<int>& nums,vector<int>& dp){
        if(idx<0) return 0;
        if(dp[idx]!=-1) return dp[idx];

        //pick
        int pick = f(idx-2,nums,dp) + nums[idx];
        //not 
        int notpick = f(idx-1,nums,dp);

        return dp[idx] = max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        //using memoised sol
        int n = nums.size();
        vector<int> dp(n,-1);
        return f(n-1,nums,dp);
    }
};