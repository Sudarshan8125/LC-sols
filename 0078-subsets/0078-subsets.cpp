class Solution {
public:

    void powersets(int i,vector<int>&ds, vector<int>& nums, vector<vector<int>>& ans){
        ans.push_back(ds);

        for(i;i<nums.size();i++){
            ds.push_back(nums[i]);
            powersets(i+1,ds,nums,ans);
            ds.pop_back();
        }
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;

        powersets(0,ds,nums,ans);
        return ans;
    }
};