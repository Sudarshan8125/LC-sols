class Solution {
public:
    void BFS(int node,vector<int>& vis,vector<vector<int>>& adj){ // to traverse one entire province..
        int n = adj.size();
        queue<int> q;
        q.push(node); //lvl 0 pushed to the queue
        vis[node] = 1;
        while(!q.empty()){
            int temp = q.front();
            q.pop();

            for(int it=0;it<n;it++){
                if(adj[temp][it] && !vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n,0);
        int prov = 0;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                prov++;
                BFS(i,vis,isConnected);
            }
        }
        return prov;
    }
};