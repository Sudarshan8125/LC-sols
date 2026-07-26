class Solution {
private:
    bool canColor(int src,vector<int>& vis,vector<vector<int>>& graph){  //detect fallacy
        vis[src] = 0;
        queue<int> q;
        q.push(src);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it:graph[node]){ //check neighbouring
                if(vis[it]==-1){
                    q.push(it);
                    vis[it] = !vis[node];
                }
                else if(vis[it] == vis[node]) return false; //neighbour having the same color
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        //ezy
        int V = graph.size(); // no.of nodes
        vector<int> vis(V,-1);
        
        for(int i=0;i<V;i++){
            if(vis[i]==-1)
                if(canColor(i,vis,graph) == false) return false;        
        }
        return true;
    }
};