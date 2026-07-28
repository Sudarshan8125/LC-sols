class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // length = num of visited cells
        int n = grid.size();
        if(grid[0][0] || grid[n-1][n-1]) return -1;
        //prefer right diagonal the most
        //1 if n-1,n-1 is pushed into queue
        //solving using plain  BFS
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        while(!q.empty()){
            int size = q.size();
            for(int k=0;k<size;k++){
                auto [dis,coord] = q.front();
                auto [i,j] = coord;
                q.pop();
                if(i==n-1 && j==n-1) return dis;
                for(int x = -1;x<=1;x++){
                    for(int y = -1; y<=1; y++){
                        int xn = x + i;
                        int yn = y + j;
                        if(xn>=0 && xn<n && yn>=0 && yn<n && grid[xn][yn] == 0){
                            q.push({dis+1,{xn,yn}});
                            grid[xn][yn] = 1; //so to nvr visit it again
                        }
                    }
                }
            }
        }
        return -1;
    }
};