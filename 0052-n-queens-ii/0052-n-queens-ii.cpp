class Solution {
public:
    int helper(int r,int n,vector<bool>&col,vector<bool>&diag1,vector<bool>&diag2){
        if(r == n){
            return 1;
        }
        int cnt = 0;
        for(int c=0;c<n;c++){

            int d1 = r+c; int d2 = r-c + (n-1); //diagonal for the curr pos
            if(!col[c] && !diag1[d1] && !diag2[d2]){ // if aint blocked
                col[c] = true;
                diag1[d1] = true;
                diag2[d2] = true;
                       
                cnt += helper(r+1,n,col,diag1,diag2);
                
                col[c] = false;
                diag1[d1] = false;
                diag2[d2] = false;
            }
        }
        return cnt;
    }
    int totalNQueens(int n) {

        vector<bool> col(n,false);
        vector<bool> diag1(2*n-1, false);
        vector<bool> diag2(2*n-1, false);

        //not an optimization problem thefo no memo shii
        return helper(0,n,col,diag1,diag2);
    }
};