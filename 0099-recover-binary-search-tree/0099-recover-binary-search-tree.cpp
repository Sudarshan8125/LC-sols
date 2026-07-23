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
private:
    TreeNode* first;
    TreeNode* second;
    TreeNode* prev;
public:
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);

        if(root->val < prev->val){
            if(!first) first = prev;
            second = root;
        }
        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        first = second = NULL;
        prev = new TreeNode(INT_MIN);

        inorder(root);
        if (first && second) {
            swap(first->val, second->val);
        }
    }
};