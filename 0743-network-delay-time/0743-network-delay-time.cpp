class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];

        for(auto it:times){
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v, w});
        }
        
        vector<int> time(n+1,INT_MAX);
        using T = pair<int,int>; //time,node
        priority_queue<T,vector<T>,greater<T>> pq;
        
        pq.push({0,k});
        time[k] = 0;
        while(!pq.empty()){
            auto [t,node] = pq.top();
            pq.pop();
            if(t>time[node]) continue;
            for(auto it:adj[node]){
                auto [next,wght] = it;

                if(t + wght < time[next]){
                    time[next] = t + wght;
                    pq.push({time[next],next});
                }
            }
        }
        int mTime = 0;
        for(int i=1;i<=n;i++){
            if(time[i] == INT_MAX) return -1;
            mTime = max(mTime,time[i]);
        }
        return mTime;
    }
};