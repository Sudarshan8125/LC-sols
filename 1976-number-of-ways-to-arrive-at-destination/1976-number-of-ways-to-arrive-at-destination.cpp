class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9 + 7;
        vector<pair<int,long long>> adj[n];
        for(auto it:roads){
            int u = it[0];
            int v = it[1];
            long long t = it[2];

            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }

        vector<long long> time(n,LLONG_MAX);
        time[0] = 0;

        using T = pair<long long,int>; // for time,node
        priority_queue<T,vector<T>,greater<T>> pq;
        pq.push({0,0});

        vector<int> ways(n,0);
        ways[0] = 1;
        while(!pq.empty()){
            auto [t,node] = pq.top();
            pq.pop();

            if (t > time[node]) continue;
            for(auto it:adj[node]){
                auto [next,edgeW] = it;

                if(t + edgeW == time[next]){
                    ways[next] = (ways[next]+ways[node])%mod;
                }
                if(t + edgeW < time[next]){
                    ways[next] = ways[node];
                    time[next] = t + edgeW;
                    pq.push({time[next],next});
                }
            }
        }
        return ways[n-1];
    }
};