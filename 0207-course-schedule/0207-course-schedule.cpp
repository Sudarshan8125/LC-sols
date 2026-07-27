class Solution {
private:
    bool dfs(int node,vector<int> adj[],vector<int>& vis,vector<int>& pathVis){
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                if(dfs(it,adj,vis,pathVis) == true) return true;
            }
            else if(pathVis[it]) return true;
        }
        pathVis[node] = 0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //if there is a cyclic dependencies then topological ordering would not be possible
        vector<int> adjLs[numCourses];
        vector<int> vis(numCourses,0);
        vector<int> pathVis(numCourses,0);
        //using both vis+pathVis

        for(auto it:prerequisites){
            int u = it[0];
            int v = it[1];

            adjLs[u].push_back(v);
        }

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,adjLs,vis,pathVis)==true) return false; // if cycle
            }
        }
        return true;
    }
};