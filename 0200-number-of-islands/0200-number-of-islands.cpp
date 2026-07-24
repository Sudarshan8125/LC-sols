class Solution {
public:
    int n,m;
    void bfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& vis){
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j] = 1;
        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            for(auto& [a,b] : dir){
                int xn = x+a;
                int yn = y+b;
                if(xn>=0 && xn<n && yn>=0 && yn<m){//for a valid coordinate
                    if(grid[xn][yn]=='1' && !vis[xn][yn]){//for unvisited land
                        q.push({xn,yn});
                        vis[xn][yn] = 1;
                    }
                }
            }   
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (!vis[i][j] && grid[i][j] == '1') {
                    ans++;
                    bfs(i, j, grid, vis);
                }
            }
        }
        return ans;
    }
};