class Solution {
public:

    void helper(int i,int s,int k,int n,vector<int>& temp,vector<vector<int>>& ans){
        
        if(temp.size()==k){
            if(s==n){
                ans.push_back(temp);
            }
            return;
        }

        if(i==10) return;
        //take
        temp.push_back(i);
        helper(i+1,s+i,k,n,temp,ans);
        temp.pop_back();

        //not take
        helper(i+1,s,k,n,temp,ans);

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;

        helper(1,0,k,n,temp,ans);
        return ans;
    }
};