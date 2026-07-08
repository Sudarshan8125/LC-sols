/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        //need a new container to extract every node along with coordi pair
        // need sort acc to columns and then acc to val// but onl keys get sorted// so req 2 maps.
        //app1
        vector<vector<int>> ans; // return structure
        if(root==NULL) return ans;

        map<int,map<int,multiset<int>>> mpp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});

        while(!q.empty()){ 
            auto [node,coord] = q.front(); //val is TreeNode*
            auto [row,col] = coord;
            q.pop();

            mpp[col][row].insert(node->val); // nested map syntax

            if(node->left) q.push({node->left,{row+1,col-1}});
            if(node->right) q.push({node->right,{row+1,col+1}});
        }

        //extraction to ans
        for(auto& colPair : mpp){ // first take col
            vector<int> colval;
            for(auto& rowPair : colPair.second){ // then fo same col take row top->bottom
                // Insert all elements from the multiset into the column vector
                colval.insert(colval.end(),rowPair.second.begin(),rowPair.second.end());
            }
            ans.push_back(colval);
        }
        return ans;
    }
};