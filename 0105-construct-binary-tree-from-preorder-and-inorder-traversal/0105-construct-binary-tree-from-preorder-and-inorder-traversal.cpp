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
    TreeNode* construct(vector<int>& preorder,vector<int>& inorder,int& i,int start,int end){

        if(start>end) return NULL;
        //locate in inorder
        int j;
        for(j=start;j<=end;j++){
            if(preorder[i] == inorder[j]){
                break;
            }
        }
        
        TreeNode* node = new TreeNode(preorder[i++]);
        node->left = construct(preorder,inorder,i,start,j-1);
        node->right = construct(preorder,inorder,i,j+1,end);

        return node;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root;
        int i=0;
        root = construct(preorder,inorder,i,0,preorder.size()-1);
        return root;
    }
};