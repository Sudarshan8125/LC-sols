class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int rcol = image[sr][sc];

        // Fix: Prevent infinite loops when the target color is the same as the current color
        if (rcol == color) return image; 

        
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc] = color;

        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int xn = x+dx[i];
                int yn = y+dy[i];

                if(xn>=0 && xn<n && yn>=0 && yn<m){
                    if(image[xn][yn] == rcol){
                        image[xn][yn] = color;
                        q.push({xn,yn});
                    }
                }

            }

        }

        return image;
    }
};