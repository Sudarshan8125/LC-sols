class Solution {
private:
    int n;
    int m;
    void dfs(int r,int c,vector<vector<char>>& board){
        if(r<0 || r>=n || c<0 || c>=m || board[r][c]!= 'O') return;

        board[r][c] = 'E';

        dfs(r+1,c,board);
        dfs(r-1,c,board);
        dfs(r,c+1,board);
        dfs(r,c-1,board);
    }
public:
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();

        // jo bhi edge pe hai that can not be surrounded
        //visit all such nodes that are at the edge
        //at last for all the unvisited nodes
        //turn them to X

        for(int i=0;i<n;i++){
            if(board[i][0] == 'O') dfs(i,0,board);
            if(board[i][m-1] == 'O') dfs(i,m-1,board);
        }

        for(int j=0;j<m;j++){
            if(board[0][j] == 'O') dfs(0,j,board);
            if(board[n-1][j] == 'O') dfs(n-1,j,board);
        }


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'E') board[i][j] = 'O';
            }
        }
        
    }
};