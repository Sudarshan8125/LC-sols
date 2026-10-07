class Solution {
public:
    // Use a set to automatically handle duplicate valid strings
    unordered_set<string> resultSet;
    
    void solve(string& s, int idx, int invalidOpen, int invalidClose, int balance, string current) {
        // Base Case: Reached the end of the string
        if (idx == s.length()) {
            if (invalidOpen == 0 && invalidClose == 0 && balance == 0) {
                resultSet.insert(current);
            }
            return;
        }
        
        // Pruning: If balance goes negative, it's invalid
        if (balance < 0) return;

        char c = s[idx];

        // OPTION 1: Skip (Delete) the current character if allowed
        if (c == '(' && invalidOpen > 0) {
            solve(s, idx + 1, invalidOpen - 1, invalidClose, balance, current);
        }
        if (c == ')' && invalidClose > 0) {
            solve(s, idx + 1, invalidOpen, invalidClose - 1, balance, current);
        }

        // OPTION 2: Keep the current character
        if (c == '(') {
            solve(s, idx + 1, invalidOpen, invalidClose, balance + 1, current + c);
        } else if (c == ')') {
            solve(s, idx + 1, invalidOpen, invalidClose, balance - 1, current + c);
        } else {
            // It's a regular letter, just append it
            solve(s, idx + 1, invalidOpen, invalidClose, balance, current + c);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int invalidOpen = 0;
        int invalidClose = 0;

        // Step 1: Count minimum misplaced parentheses
        for (char c : s) {
            if (c == '(') {
                invalidOpen++;
            } else if (c == ')') {
                if (invalidOpen > 0) {
                    invalidOpen--; 
                } else {
                    invalidClose++; 
                }
            }
        }

        // Step 2: Begin backtracking
        solve(s, 0, invalidOpen, invalidClose, 0, "");
        
        // Convert set to vector for the final output
        return vector<string>(resultSet.begin(), resultSet.end());
    }
};
 