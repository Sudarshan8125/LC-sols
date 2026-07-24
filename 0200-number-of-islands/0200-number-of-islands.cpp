class Solution {
public:
    int n,m;
    void bfs(int i,int j,vector<vector<char>>& grid){
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j] = '2';
        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            for(auto& [a,b] : dir){
                int xn = x+a;
                int yn = y+b;
                if(xn>=0 && xn<n && yn>=0 && yn<m){//for a valid coordinate
                    if(grid[xn][yn]=='1'){//for unvisited land
                        q.push({xn,yn});
                        grid[xn][yn] = '2';
                    }
                }
            }   
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (grid[i][j] == '1') {
                    ans++;
                    bfs(i, j, grid);
                }
            }
        }
        return ans;
    }
};