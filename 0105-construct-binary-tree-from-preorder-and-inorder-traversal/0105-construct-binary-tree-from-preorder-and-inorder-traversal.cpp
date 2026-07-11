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
    TreeNode* construct(unordered_map<int,int>& inorder,vector<int>& preorder,int& i,int start,int end){

        if(start>end) return NULL;
        //locate in inorder
        int j = inorder[preorder[i]];
        

        TreeNode* node = new TreeNode(preorder[i++]);
        node->left = construct(inorder,preorder,i,start,j-1);
        node->right = construct(inorder,preorder,i,j+1,end);

        return node;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        unordered_map<int,int> in;

        for(int j=0;j<n;j++) in[inorder[j]] = j;
            

        TreeNode* root;
        int i=0;
        root = construct(in,preorder,i,0,n-1);
        return root;
    }
};