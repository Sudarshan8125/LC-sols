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
    bool inorder(TreeNode* root,long long& mini){
        if(root == NULL) return true;

        if(!inorder(root->left,mini)) return false;

        if(mini >= root->val) return false;
        mini = root->val;

        if(!inorder(root->right,mini)) return false;

        return true;
    }
    bool isValidBST(TreeNode* root) {
        // the inorder traversal should be ascending
        long long mini = LLONG_MIN;
        return inorder(root,mini);
    }
};