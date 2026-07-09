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
private:
    // Helper function passing p and q by reference (&)
    TreeNode* lcaHelper(TreeNode* root, TreeNode* &p, TreeNode* &q) {
        if (root == nullptr || root == p || root == q) return root;

        TreeNode* left = lcaHelper(root->left, p, q);
        TreeNode* right = lcaHelper(root->right, p, q);

        if (left && right) return root;
        return left ? left : right;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        return lcaHelper(root, p, q);
    }
};
