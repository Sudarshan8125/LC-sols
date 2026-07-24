class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int time = 0;
        int fresh_oranges = 0;

        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2) {
                    q.push({i, j});
                } else if(grid[i][j] == 1) {
                    fresh_oranges++;
                }
            }
        }

        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};
        //multi source bfs 
        while(!q.empty()){
            int size = q.size();
            bool rotten = false;

            for(int k=0;k<size;k++){
                auto [a,b] = q.front();
                q.pop();

                for(int i=0;i<4;i++){
                    int xn = a+dx[i];
                    int yn = b+dy[i];

                    if(xn>=0 && xn<n && yn>=0 && yn<m){//for a valid coordinate
                        if(grid[xn][yn] == 1){
                            q.push({xn,yn});
                            grid[xn][yn] = 2;
                            fresh_oranges--;
                            rotten = true;
                        }
                    }
                }
            }
            if(rotten) time++;
        }
        return fresh_oranges == 0 ? time : -1;     
    }
};