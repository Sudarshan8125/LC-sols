class Solution {
public:
    void f(int ind,vector<int>& ds,vector<int>& nums,vector<vector<int>>& ans){
        int n = nums.size();
        //using pick and not pick approach
        if(ind==n){
            ans.push_back(ds);
            return;
        }

        //pick
        ds.push_back(nums[ind]);
        f(ind + 1, ds, nums, ans);
        ds.pop_back();
        //not pick matlab vo element value mat uthao//cuase fo ex 1 not pick hai matlab 1 ni uthana ab age agr uth gya to repeted comb
        
        while(ind+1<n && nums[ind]==nums[ind+1]) ind++;
        f(ind+1,ds,nums,ans);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ds;
        vector<vector<int>> ans;
        f(0,ds,nums,ans);
        return ans;
    }
};