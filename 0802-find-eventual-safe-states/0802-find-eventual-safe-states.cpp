class Solution {
private:
    bool dfs(int node,vector<int>& vis,vector<vector<int>>& graph){
        
        vis[node] = 1;//mark unv as being visited

        for(auto it:graph[node]){
            if(!vis[it]){
                if(dfs(it,vis,graph) == true){ //if age cycle exits so during backtrck mrk unsafe
                    vis[node] = -1;
                    return true;
                }
            }
            else if(vis[it] == -1) {
                vis[node] = -1; // FIX 2: Mark current node unsafe before exiting
                return true; 
            }
            else if(vis[it] == 2) {
                // This neighbor is safe. 
                // Do NOT return false yet! We must check OTHER neighbors first.
                continue; 
            }
            else if(vis[it] == 1){ 
                vis[node] = -1; // FIX 3: Mark current node unsafe before exiting
                return true;
            }
        }

        //for node jiske sare options check hogye
        vis[node] = 2; //safe
        return false; //out of neighbours
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        // if any in cycle tag unsafe // if any lead to cycle also tag unsafe
        // if node alr been visited ->check whether safe/unsafe->if safe curr path also safe
        // if unsafe->whole node be unsafe and all currently being visited.
        // 0->unvisited  -1->unsafe  1->being visited state not known 2->safe
        vector<int> vis(V,0);

        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,graph);
            }
        }
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(vis[i]==2) ans.push_back(i);
        }

        return ans;
    }
};