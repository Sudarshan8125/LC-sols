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
    stack<TreeNode*> s1;
    stack<TreeNode*> s2;
public:
    bool findTarget(TreeNode* root, int k) {
        pushAllL(root);
        pushAllR(root);
        int l = next();
        int r = before();
        while(l!=r){
            if(l+r > k) r = before();
            else if(l+r < k) l = next();
            else return true; 
        }
        return false;
    }
private:
    void pushAllL(TreeNode* root){
        while(root){
            s1.push(root);
            root = root->left;
        }
    }
    void pushAllR(TreeNode* root){
        while(root){
            s2.push(root);
            root = root->right;
        }
    }
    int next(){
        TreeNode* temp = s1.top();
        s1.pop();
        pushAllL(temp->right);
        return temp->val;
    }
    int before(){
        TreeNode* temp = s2.top();
        s2.pop();
        pushAllR(temp->left);
        return temp->val;
    }
};