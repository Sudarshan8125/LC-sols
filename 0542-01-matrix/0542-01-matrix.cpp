class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
         // insert zeros and then solve for distance
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> ans(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0) q.push({i,j}); // all zeros pushed
            }
        }

        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};
        int lvl = 0;
        while(!q.empty()){
            int size = q.size();
            lvl++;
            for(int c=0;c<size;c++){ //pop out an entire level
                auto [a,b] = q.front();
                q.pop();

                for(int i=0;i<4;i++){
                    int xn = a + dx[i];
                    int yn = b + dy[i];

                    if(xn>=0 && xn<n && yn>=0 && yn<m){
                        if(mat[xn][yn] == 1){
                            mat[xn][yn] = 0; //decays to 0 or gets rotten
                            q.push({xn,yn});
                            ans[xn][yn] = lvl;
                        }
                    }
                }
            }
        }
        return ans;
    }
};