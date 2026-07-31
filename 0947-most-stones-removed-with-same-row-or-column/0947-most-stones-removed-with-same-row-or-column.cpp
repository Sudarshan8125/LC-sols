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
    int removeStones(vector<vector<int>>& stones) { //stones-->coordinates collection vector
        int n = stones.size(); //total stones that is 0->{0,0} 1->{0,1} etc
        //build the graph//
        DisjointSet ds(n);
        for(int i=0;i<n-1;i++){
            for(int j=i;j<n;j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    ds.unionByRank(i,j);
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(ds.findUPar(i) == i) cnt++;
        }
        return n-cnt;
    }
};