class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();

        // define edge weight as the diff bw val 
        vector<vector<int>> effort(r,vector<int>(c,INT_MAX));

        set<pair<int,pair<int,int>>> st;
        st.insert({0,{0,0}});
        effort[0][0] = 0;

        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        while(!st.empty()){
            auto [eff,coord] = *(st.begin());
            auto [x,y] = coord;
            st.erase(st.begin());
            if(x == r-1 && y== c-1) return effort[r-1][c-1];
            for(int i=0;i<4;i++){
                int xn = x + dx[i];
                int yn = y + dy[i];

                if(xn>=0 && xn<r && yn>=0 && yn<c){
                    int eff = abs(heights[x][y] - heights[xn][yn]);
                    eff = max(effort[x][y],eff); //bec that the real eff
                    if(effort[xn][yn]>eff){
                        if(effort[xn][yn] !=INT_MAX) st.erase({effort[xn][yn],{xn,yn}});
                        effort[xn][yn] = eff;
                        st.insert({effort[xn][yn],{xn,yn}});
                    }
                }
            }
        }
        return effort[r-1][c-1];
    }
};