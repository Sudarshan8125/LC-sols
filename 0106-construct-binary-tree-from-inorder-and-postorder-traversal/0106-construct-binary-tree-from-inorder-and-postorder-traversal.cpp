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
    TreeNode* construct(unordered_map<int,int>& in,vector<int>&postorder,int &i,int start,int end){
        if(start>end) return NULL;

        //find left and right subs thereby root index
        int inRoot = in[postorder[i]]; // indx in inorder array

        TreeNode* node = new TreeNode(postorder[i--]);

        node->right = construct(in,postorder,i,inRoot+1,end);
        node->left = construct(in,postorder,i,start,inRoot-1);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        unordered_map<int,int> in;
        for(int j=0; j<n; j++) in[inorder[j]] = j;
        
        int i=n-1;
        return construct(in,postorder,i,0,n-1);
    }
};