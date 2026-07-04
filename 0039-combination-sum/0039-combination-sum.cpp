class Solution {
public:

    void combi(int i,int target,vector<int>& ds,vector<int>& arr,vector<vector<int>>& ans){
        int n = arr.size();
        if(target == 0){
            ans.push_back(ds);
            return;
        }

        for(i;i<n;i++){
            if(target<arr[i]) continue;

            ds.push_back(arr[i]);
            combi(i,target-arr[i],ds,arr,ans);
            ds.pop_back();
        }

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;

        combi(0,target,ds,candidates,ans);
        return ans;
    }
};