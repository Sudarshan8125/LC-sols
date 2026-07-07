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

    int heightdfs(TreeNode* root){
        if(root == NULL) return 0;

        int lh = heightdfs(root->left);
        int rh = heightdfs(root->right);

        if(lh == -1 || rh==-1) return -1;
        if(abs(lh-rh)>1) return -1;
        else return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        // better approach is to check in the height func itself so that it doesnt need to check again again
        return heightdfs(root) !=-1;
    }
};