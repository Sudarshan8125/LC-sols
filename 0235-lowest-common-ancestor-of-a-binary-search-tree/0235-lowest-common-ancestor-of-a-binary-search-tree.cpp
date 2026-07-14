/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return root;
        int curr = root->val;
        if(curr>p->val && curr>q->val){
            return lowestCommonAncestor(root->left,p,q);// p,q smaller than curr
        }
        else if(curr<p->val && curr<q->val){
            return lowestCommonAncestor(root->right,p,q);// p,q greater than curr
        }
        return root;
    }
};