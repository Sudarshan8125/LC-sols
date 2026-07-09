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
    unordered_map<TreeNode*,TreeNode*> parent;
    bool DFS(TreeNode* node, TreeNode* target) {
        if (node == target) return true; // Found it!

        if (node->left) {
            parent[node->left] = node;
            if (DFS(node->left, target)) return true; // Crash stop! Return true to up-level parent
        }
        if (node->right) {
            parent[node->right] = node;
            if (DFS(node->right, target)) return true; // Crash stop! Return true to up-level parent
        }
        return false; // Target not in this subtree
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        DFS(root,target);
        // unordered_map<TreeNode*,TreeNode*> parent; // to save node,parent

        // queue<TreeNode*> q;
        // q.push(root);
        // while(!q.empty()){  //to store parent of evry node for back traversal
        //     TreeNode* temp = q.front();
        //     q.pop();

        //     if(temp->left){
        //         q.push(temp->left);
        //         parent[temp->left] = temp;
        //     }
        //     if(temp->right){
        //         q.push(temp->right);
        //         parent[temp->right] = temp;
        //     }
        
        // }

        //logic to search in all directions
        //bfs type traversal
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q2;
        q2.push(target);
        visited.insert(target);
        while(k--){
            int size = q2.size();
            for(int i=0;i<size;i++){
                TreeNode* temp = q2.front();
                q2.pop();
                //place all nodes of all direction traversal in queue

                if(temp->left && !visited.count(temp->left)){
                    q2.push(temp->left);
                    visited.insert(temp->left);
                }
                if(temp->right && !visited.count(temp->right)){
                    q2.push(temp->right);
                    visited.insert(temp->right);
                }
                if(parent.find(temp) != parent.end() && !visited.count(parent[temp])){
                    q2.push(parent[temp]);
                    visited.insert(parent[temp]);
                }
            }
        }

        vector<int> ans;
        while(!q2.empty()){
            ans.push_back(q2.front()->val);
            q2.pop();
        }

        return ans;
    }
};