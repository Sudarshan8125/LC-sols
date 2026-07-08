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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;    

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int right = 0;
            for(int i=0;i<size;i++){ // loop for level wised traversal
                auto node = q.front();
                q.pop();
                if(!right){
                    ans.push_back(node->val);
                    right =1;
                }
                if(node->right)  q.push(node->right);
                if(node->left) q.push(node->left);
            }
            right = 0;
        }
        return ans;
    }
};