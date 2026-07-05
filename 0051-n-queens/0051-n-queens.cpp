class Solution {
public:
    void helper(int row, int n, unordered_set<int>& cols, 
                unordered_set<int>& diag1, unordered_set<int>& diag2, 
                vector<string>& ds, vector<vector<string>>& ans) {
        
        if (row == n) {
            ans.push_back(ds);
            return;
        }

        for (int col = 0; col < n; col++) {
            // Standard N-Queens Attack Checks:
            // 1. Column occupied?
            // 2. Main Diagonal (row - col) occupied?
            // 3. Anti Diagonal (row + col) occupied?
            if (cols.count(col) || diag1.count(row - col) || diag2.count(row + col)) {
                continue;
            }

            // --- Place Queen ---
            cols.insert(col);
            diag1.insert(row - col);
            diag2.insert(row + col);

            string row_str(n, '.');
            row_str[col] = 'Q';
            ds.push_back(row_str);

            // --- Recurse ---
            helper(row + 1, n, cols, diag1, diag2, ds, ans);

            // --- Backtrack ---
            ds.pop_back();
            cols.erase(col);
            diag1.erase(row - col);
            diag2.erase(row + col);
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> ds;
        unordered_set<int> cols, diag1, diag2;
 
        helper(0, n, cols, diag1, diag2, ds, ans);
        return ans;
    }
};
