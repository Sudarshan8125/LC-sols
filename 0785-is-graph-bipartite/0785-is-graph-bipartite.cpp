class Solution {
private:
    bool dfs(int src,int col,vector<int>& vis,vector<vector<int>>& graph){
        vis[src] = col;

        for(auto it:graph[src]){ //for adj nodes
            if(vis[it]==-1){
                if(dfs(it,!col,vis,graph)==false) return false;
            }
            else if(vis[it] == vis[src]) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        //using dfs
        int V = graph.size();
        vector<int> vis(V,-1);

        for(int i=0;i<V;i++){
            if(vis[i]==-1){
                if(dfs(i,0,vis,graph)==false) return false;
            }
        }
        return true;
    }
};