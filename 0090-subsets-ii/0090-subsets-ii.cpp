class Solution {
public:

    void powersets(int start_idx,vector<int>& ds,vector<int>& nums,vector<vector<int>>& ans){
        ans.push_back(ds);

        int prev = -1;
        for(int i = start_idx;i<nums.size();i++){
            if(i>start_idx && nums[i] == nums[i-1]) continue;  //i>start_idx so as to allow 1st choice in new rec call
                                                                //i.e to allow depth search
            ds.push_back(nums[i]);
            powersets(i+1,ds,nums,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        powersets(0,ds,nums,ans);
        return ans;
    }
};