class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        int depth = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                depth++;
            } else {
                depth--;
                // If the previous character was '(', we found a base core "()"
                if (s[i - 1] == '(') {
                    // 1 << depth calculates 2 raised to the power of depth
                    score += (1 << depth); 
                }
            }
        }
        
        return score;
    }
};