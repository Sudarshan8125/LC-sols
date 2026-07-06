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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) return ans;

        stack<pair<TreeNode*,int>> st;
        st.push({root,0});

        while(!st.empty()){
            auto [node,vis] = st.top();
            st.pop();

            if(vis==1 || !node->left && !node->right){
                ans.push_back(node->val);
                continue;
            }

            if(node->right) st.push({node->right,0});
            st.push({node,1});
            if(node->left) st.push({node->left,0});
        }
        return ans;
    }
};