class Solution {
public:
    void helper(string& temp,int first,int second,vector<string>& ans){
        if(first==0 && second==0){
            ans.push_back(temp);
            return;
        }

        if(first){
            temp.push_back('(');
            helper(temp,first-1,second,ans);
            temp.pop_back();
        }
        if(second>first){
            temp.push_back(')');
            helper(temp,first,second-1,ans);
            temp.pop_back();
        }
        
        return;

    }
    vector<string> generateParenthesis(int n) {
        // backtraciing type question

        string temp = {};
        int eff = 0;
        vector<string> ans;
        helper(temp,n,n,ans);
        return ans;
    }
};