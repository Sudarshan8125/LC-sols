class Solution {
public:

    void combi(int i,int target,vector<int>& arr,vector<int>&ds,vector<vector<int>>& ans){
        int n = arr.size();
        if(target==0){
            ans.push_back(ds);
            return;
        }

        int prev_val=-1;
       for(i;i<n;i++){     
            if(prev_val==arr[i]) continue;
            if(target<arr[i]) break;
            else{
                prev_val = arr[i];
                ds.push_back(arr[i]);
                combi(i+1,target-arr[i],arr,ds,ans);
                ds.pop_back();
            }
       }
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(),candidates.end());
        combi(0,target,candidates,ds,ans);

        return ans;
    }
};