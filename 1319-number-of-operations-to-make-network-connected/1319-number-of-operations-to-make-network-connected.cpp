class DisjointSet{
    vector<int> parent,rank;
  public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i] = i;
    }
    
    
    int findUPar(int node){
        if(parent[node] == node) return node;
        else return parent[node] = findUPar(parent[node]);
    }
    
    void unionByRank(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        
        if(ulp_u == ulp_v) return; //cause they are part of one i.e. part of same component
        
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // CRITICAL ELIMINATION: If total cables are less than n-1, connection is impossible
        if (connections.size() < n - 1) return -1;

        DisjointSet ds(n);
        for (auto it : connections) {
            ds.unionByRank(it[0], it[1]);
        }

        // Count independent components
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (ds.findUPar(i) == i) cnt++;
        }

        // To connect 'cnt' components, we need exactly 'cnt - 1' cables
        return cnt - 1;
    }
};
