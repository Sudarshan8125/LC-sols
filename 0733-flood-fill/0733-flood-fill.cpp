class Solution {
public:
    int n;
    int m;

    void dfs(vector<vector<int>>& image,int sr,int sc,int rcol,int col){

        if(sr<0 || sr>=n || sc<0 || sc>=m || image[sr][sc]!=rcol) return;

        image[sr][sc] = col;
        dfs(image,sr+1,sc,rcol,col);
        dfs(image,sr-1,sc,rcol,col);
        dfs(image,sr,sc+1,rcol,col);
        dfs(image,sr,sc-1,rcol,col);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size();
        m = image[0].size();
        int rcol = image[sr][sc];

        // Fix: Prevent infinite loops when the target color is the same as the current color
        if (rcol == color) return image; 
        
        dfs(image,sr,sc,rcol,color);

        return image;
    }
};