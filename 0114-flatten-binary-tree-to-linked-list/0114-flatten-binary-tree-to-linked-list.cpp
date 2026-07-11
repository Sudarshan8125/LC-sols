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
    void preorder(TreeNode* root,vector<TreeNode*>& pre){
        if(root == NULL) return;

        pre.push_back(root);
        preorder(root->left,pre);
        preorder(root->right,pre);
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*> pre;
        preorder(root,pre);


        for(int i=1;i<pre.size();i++){
            root->left = NULL;
            root->right = pre[i];
            root = root->right;
        }

    }
};