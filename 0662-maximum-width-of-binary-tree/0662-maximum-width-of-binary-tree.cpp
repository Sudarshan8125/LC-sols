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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;

        int maxlen = 0;
        // FIX: Use unsigned long long to strictly prevent overflow on deep trees
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            unsigned long long first_index = q.front().second;
            unsigned long long last_index = q.front().second;

            for (int i = 0; i < size; i++) {
                auto [node, idx] = q.front(); 
                q.pop();

                last_index = idx;
                
                // FIX: Cast the result of the width calculation back to int for maxlen
                maxlen = max(maxlen, static_cast<int>(last_index - first_index + 1));

                unsigned long long idn = idx - first_index;

                if (node->left) q.push({node->left, 2 * idn + 1});
                if (node->right) q.push({node->right, 2 * idn + 2});
            }
        }
        return maxlen;
    }
};
