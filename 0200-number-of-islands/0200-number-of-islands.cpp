class Solution {
public:
    int n,m;
    // void bfs(int i,int j,vector<vector<char>>& grid){
    //     queue<pair<int,int>> q;
    //     q.push({i,j});
    //     grid[i][j] = '2';
    //     vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    //     while(!q.empty()){
    //         auto [x,y] = q.front();
    //         q.pop();

    //         for(auto& [a,b] : dir){
    //             int xn = x+a;
    //             int yn = y+b;
    //             if(xn>=0 && xn<n && yn>=0 && yn<m){//for a valid coordinate
    //                 if(grid[xn][yn]=='1'){//for unvisited land
    //                     q.push({xn,yn});
    //                     grid[xn][yn] = '2';
    //                 }
    //             }
    //         }   
    //     }
    // }

    void dfs(int x,int y,vector<vector<char>>& grid){
        if(x<0 || x>=n || y<0 || y>=m || grid[x][y]!='1') return;

        grid[x][y] = '2';

        // 3. Recursive calls for 4 directions (faster than a loop)
        dfs(x+1,y,grid);
        dfs(x-1,y,grid);
        dfs(x,y+1,grid);
        dfs(x,y-1,grid);

        //or loop
        // int row[] = {1,-1,0,0};
        // int col[] = {0,0,1,-1};
        // for(int i=0;i<4;i++){
        //     dfs(x+row[i],y+col[i],grid);
        // }

        //or loop
        // pair<int,int> dir[] = {{0,1},{0,-1},{1,0},{-1,0}};
        // for(auto& [a,b] : dir){
        //     dfs(x+a,y+b,grid);
        // }
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (grid[i][j] == '1') {
                    ans++;
                    dfs(i, j, grid);
                }
            }
        }
        return ans;
    }
};