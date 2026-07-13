/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> arr;
            for(int i=0;i<size;i++){
                Node* temp = q.front();
                q.pop();

                int childcnt = temp->children.size();
                for(int i=0;i<childcnt;i++){
                    q.push(temp->children[i]);
                }

                arr.push_back(temp->val);
            }  
            ans.push_back(arr);       
        }
        return ans;
    }
};