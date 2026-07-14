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

    TreeNode* construct(TreeNode* root,vector<int>& preorder,int ps,int pe){
        if(ps>pe) return NULL;
        root = new TreeNode(preorder[ps]);

        int i;
        for(i=ps+1;i<=pe;i++){
            if(preorder[i]>preorder[ps]) break;
        }

        root->left = construct(root->left,preorder,ps+1,i-1);
        root->right = construct(root->right,preorder,i,pe);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root;
        return construct(root,preorder,0,preorder.size()-1);
    }
};