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
class BSTiterator{
private:
    stack<TreeNode*> st;
    bool rev;
    void pushAll(TreeNode* root){
        while(root){
            st.push(root);
            if(!rev) root = root->left;
            else root = root->right;
        }
    }
public:
    BSTiterator(TreeNode* root,bool flag){
        rev = flag;
        pushAll(root);
    }

    //next in case of rev->false else before//
    int next(){
        TreeNode* temp = st.top();
        st.pop();
        if(!rev) pushAll(temp->right);
        else pushAll(temp->left);        
        return temp->val;
    }
};

class Solution {
public:
    //striver style solution
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;

        BSTiterator l(root,false);
        BSTiterator r(root,true);

        int i = l.next();
        int j = r.next();

        while(i<j){
            if(i+j > k) j = r.next();
            else if (i+j < k) i = l.next();
            else return true;
        }
        return false;
    }
};