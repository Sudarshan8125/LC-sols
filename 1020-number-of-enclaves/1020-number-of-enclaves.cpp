class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        //solving using bfs
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(grid[i][0] == 1) {
                q.push({i,0});
                grid[i][0] = 2;
            }
            if(grid[i][m-1] == 1) {
                q.push({i,m-1});
                grid[i][m-1] = 2;
            }
        }
        for(int j=0;j<m;j++){
            if(grid[0][j] == 1) {
                q.push({0,j});
                grid[0][j] = 2;
            }
            if(grid[n-1][j] == 1) {
                q.push({n-1,j});
                grid[n-1][j] = 2;
            }
        }
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int xn = r+dx[i];
                int yn = c+dy[i];

                if(xn>=0 && xn<n && yn>=0 && yn<m){
                    if(grid[xn][yn] == 1){
                        grid[xn][yn] = 2;
                        q.push({xn,yn});
                    }
                }
            }
        }
        int cnt =0; 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1) cnt++;
            }
        }
        return cnt;
    }
};