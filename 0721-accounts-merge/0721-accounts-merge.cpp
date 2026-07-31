class DisjointSet{
    vector<int> parent,rank;
  public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(parent[node] == node) return node;
        else return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);

        unordered_map<string,int> mails; //mails and curr vtx
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mails.find(accounts[i][j]) != mails.end()) {
                    //mergeboth usernames and we would do this by merging their usernames cause merging any predominantly merges parent
                    ds.unionByRank(mails[accounts[i][j]] , i); //merge prev mail vertex with current vertex
                }
                mails[accounts[i][j]] = i;
            }
        }

        unordered_map<int,vector<string>> merge;
        for(const auto& [mail,vertex] : mails){
            merge[ds.findUPar(vertex)].push_back(mail);
        } // push every mail under its ultimate parent/vertex

        vector<vector<string>> ans;
        for(auto& [par,mail_list]:merge){
            sort(mail_list.begin(),mail_list.end());

            vector<string> temp;
            temp.push_back(accounts[par][0]);
            temp.insert(temp.end(),mail_list.begin(),mail_list.end());
            ans.push_back(temp);
        }
        return ans;
    }
};