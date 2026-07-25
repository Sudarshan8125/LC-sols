class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
         // insert zeros and then solve for distance
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> ans(n,vector<int>(m,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    q.push({i,j}); // all zeros pushed
                    ans[i][j] = 0;
                }
            }
        }

        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int xn = r + dx[i];
                int yn = c + dy[i];

                if(xn>=0 && xn<n && yn>=0 && yn<m){
                    if(ans[xn][yn] == -1){
                        ans[xn][yn] = ans[r][c] + 1; // Distance is parent distance + 1
                        q.push({xn, yn});           // Push to queue to explore its neighbors later
                    }
                }
            }
        }
        return ans;
    }
};