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

    int Lheight(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + Lheight(root->left);
    }

    int Rheight(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + Rheight(root->right);
    }

    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        if(!root->left && !root->right) return 1;

        int lh = Lheight(root);
        int rh = Rheight(root);

        if(lh == rh) return pow(2,lh) - 1;
        else return 1 + countNodes(root->left) + countNodes(root->right);
    }
};