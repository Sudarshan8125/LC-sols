
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
        //first access the num of cables we have
        // then if even forming the mst is taking us more than we have we cant ret -1
        // else if we can manage MST ke sum se jada cable hai then we would need to remove = no of new connction k brabar cables. new conn = no.of not connected nodes.

        int c = connections.size(); //no of cable;
        int used_C = 0;
        DisjointSet ds(n);
        for(auto it:connections){
            int u = it[0];
            int v = it[1];

            if(ds.findUPar(u)!=ds.findUPar(v)){
                ds.unionByRank(u,v);
                used_C++;
            }
        }

        //now for the rem we would req diff_comp_cnt-1 cables
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(ds.findUPar(i)==i) cnt++;
        }
        used_C += cnt-1;
        if(used_C > c) return -1;
        else return cnt-1;
    }
};