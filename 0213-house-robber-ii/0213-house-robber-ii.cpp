class Solution {
public:
    int f(int idx,vector<int>& nums,vector<int>& dp,bool flag){

        if(idx<0) return 0;
        if(idx == 0){
            if(flag==1) return nums[0];
            else return 0;
        }

        if(dp[idx]!=-1) return dp[idx];


        int take = f(idx-2,nums,dp,flag) + nums[idx];
        int nottake = f(idx-1,nums,dp,flag);

        return dp[idx] = max(take,nottake);
    }


    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        bool flag = 1;
        return max(f(n-2,nums,dp1,flag) , f(n-1,nums,dp2,!flag));
    }
};