class Solution { 
public: 
    int minimumEffortPath(vector<vector<int>>& heights) { 
        int r = heights.size(); 
        int c = heights[0].size(); 
        
        vector<vector<int>> effort(r, vector<int>(c, INT_MAX)); 
        // Min-heap storing: {effort, {x, y}}
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq; 
        
        pq.push({0, {0, 0}}); 
        effort[0][0] = 0; 
        
        int dx[] = {-1, 1, 0, 0}; 
        int dy[] = {0, 0, -1, 1}; 
        
        while(!pq.empty()){ 
            auto [eff, coord] = pq.top(); 
            auto [x, y] = coord; 
            pq.pop(); 
            
            // Early exit as soon as we reach the destination
            if(x == r - 1 && y == c - 1) return eff; 
            
            // Skip outdated pairs with higher effort
            if(eff > effort[x][y]) continue; 
            
            for(int i = 0; i < 4; i++){ 
                int xn = x + dx[i]; 
                int yn = y + dy[i]; 
                
                if(xn >= 0 && xn < r && yn >= 0 && yn < c){ 
                    int next_eff = max(eff, abs(heights[x][y] - heights[xn][yn])); 
                    
                    if(effort[xn][yn] > next_eff){ 
                        effort[xn][yn] = next_eff; 
                        pq.push({next_eff, {xn, yn}}); 
                    } 
                } 
            } 
        } 
        return 0; 
    } 
};
