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
        // strivers implementation 
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* node = root;
        while(true){
            if(node != NULL){
                st.push(node);
                node = node->left;
            }
            else{
                if(st.empty()) break; //because left null k baad sidhha node cut 2nd null k baad sidha parent node cutt
                TreeNode* parent = st.top(); // 2nd null ke baad sidha backtrack to prev node since root would be popped
                st.pop(); // parent popped
                ans.push_back(parent->val);
                node = parent->right;
            }
        }
        return ans;
    }
};