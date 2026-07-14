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
    TreeNode* LCA(TreeNode* root,int min,int max){
        if(root==NULL || root->val>=min && root->val<=max) return root;

        if(root->val < min) return LCA(root->right,min,max);
        return LCA(root->left,min,max);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        int x = min(p->val,q->val);
        int y = max(p->val,q->val);
        return LCA(root,x,y);
    }
};