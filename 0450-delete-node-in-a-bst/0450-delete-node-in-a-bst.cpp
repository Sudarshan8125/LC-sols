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
    TreeNode* findmax(TreeNode* root){
        while(root->right!=NULL) root = root->right;
        return root; 
    }

    TreeNode* helper(TreeNode *root){
        if(root->left == NULL) return root->right;
        if(root->right == NULL) return root->left;
        TreeNode* rightSUBT = root->right;
        TreeNode* Lmax = findmax(root->left);
        Lmax->right = rightSUBT;

        return root->left;
    }



    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;
        if(root->val == key) return helper(root); // helper fxn will help sort a subtree

        TreeNode* dummy = root;
        while(root){
            if(key < root->val){
                if(root->left && root->left->val == key){
                    root->left = helper(root->left);
                    break;
                }
                else root = root->left;
            }
            else{
                if(root->right && root->right->val==key){
                    root->right = helper(root->right);
                    break;
                }
                else root = root->right;
            }
        }
     return dummy;
    }
};