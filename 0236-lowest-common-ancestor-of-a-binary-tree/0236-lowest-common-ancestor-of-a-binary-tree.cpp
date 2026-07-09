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

    bool findPath(TreeNode* root,TreeNode* tar,vector<TreeNode*>& ds){
        if(root == NULL) return false;

        ds.push_back(root);
        if(tar == root) return true;

        if(findPath(root->left,tar,ds) || findPath(root->right,tar,ds) == true){
            return true;
        }
        ds.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //brute solution using 2 loops
        vector<TreeNode*> pt1;
        vector<TreeNode*> pt2;

        findPath(root,p,pt1);
        findPath(root,q,pt2);

        int size = min(pt1.size(),pt2.size());
        int i;
        for(i = 0; i<size; i++){
            if(pt1[i]!=pt2[i]) break;
        }

        return pt1[i-1];
    }
};