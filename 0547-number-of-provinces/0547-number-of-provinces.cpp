class DisjointSet{
    vector<int> rank,parent;
  public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i = 0;i<n;i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(parent[node]==node) return node;
        else return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_v == ulp_u) return;

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        // dis joint set solution
        int n = isConnected.size(); //-->no of vertex
        int m = isConnected[0].size();
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isConnected[i][j]==1 && i!=j){
                    if(ds.findUPar(i+1)!=ds.findUPar(j+1)){
                        ds.unionByRank(i+1,j+1);
                    }
                }
            }
        }
        unordered_set<int> st;
        for(int i=1;i<=n;i++){
            st.insert(ds.findUPar(i));
        }
        return st.size();
    }
};