class Solution {
public:
    void f(int ind,vector<int>& ds,vector<int>& nums,vector<vector<int>>& ans){
        int n = nums.size();
        //using for loop to skip non pick wale dupes
        ans.push_back(ds);

        for(int i=ind;i<n;i++){

            if(i>ind && nums[i] == nums[i-1]) continue;

            ds.push_back(nums[i]);
            f(i+1,ds,nums,ans);
            ds.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ds;
        vector<vector<int>> ans;
        f(0,ds,nums,ans);
        return ans;
    }
};