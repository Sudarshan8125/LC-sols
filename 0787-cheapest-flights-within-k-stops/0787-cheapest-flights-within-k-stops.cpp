class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //directed graph
        //run for k times and submit the solution..
        vector<pair<int,int>> adj[n];
        for(auto it:flights){
            int f = it[0];
            int t = it[1];
            int p = it[2];

            adj[f].push_back({t,p});
        }

        vector<int> prices(n,INT_MAX);
        using T = pair<int,pair<int,int>>; //price,node,stopNumber
        queue<T> q;

        q.push({0,{src,0}}); //normal bfs thing
        prices[src] = 0;
        int pmin = INT_MAX;
        while(!q.empty()){
            auto [p,info] = q.front();
            auto [node,stop] = info;
            q.pop();
            if(node == dst && stop<=k+1){
                pmin = min(pmin,p);
            }

            for(auto [next,fare]:adj[node]){
                if(p + fare < prices[next]){
                    prices[next] = p + fare;
                    q.push({prices[next],{next,stop+1}});
                }
            }
        }
        return pmin == INT_MAX ? -1:pmin;
    }
};