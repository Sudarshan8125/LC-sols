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
   int findKth(TreeNode* root, int& k) {
        // Base case: If we hit a NULL pointer (X), return -1
        if (root == nullptr) return -1;

        // 1. Traverse the Left Subtree
        int left = findKth(root->left, k);
        
        // EARLY EXIT CHECK: If the left subtree found the answer, 
        // bubble it up immediately and skip everything else!
        if (left != -1) return left;

        // 2. Process Current Node
        k--;
        if (k == 0) return root->val; // Target found!

        // 3. Traverse the Right Subtree
        return findKth(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        return findKth(root, k);
    }
};