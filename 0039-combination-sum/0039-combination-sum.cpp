class Solution {
public:

    void helper(vector<int>& candidates,int i,int target,vector<int>&temp, vector<vector<int>>& ans){
        int n = candidates.size();
        if(i==n){
            if(target == 0){
                ans.push_back(temp);
            }
            return;
        }

        if(target>=candidates[i]){
            temp.push_back(candidates[i]);
            helper(candidates,i,target-candidates[i],temp,ans);
            temp.pop_back();
        }
        
        helper(candidates,i+1,target,temp,ans);
        

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        helper(candidates,0,target,temp,ans);
        return ans;
    }
};