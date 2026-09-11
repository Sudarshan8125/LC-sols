class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int n = matrix.size();
        int m = matrix[0].size();

        int maxx = 0;
        vector<int> heights(m, 0);

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }


            int maxans = 0;
            stack<int> st;
            
            // Fix: Run up to 'm' (inclusive) to clear out the stack
            for (int j = 0; j <= m; j++) {
                // Assign a virtual height of 0 at index 'm' to pop everything
                int current_height = (j == m) ? 0 : heights[j];

                while (!st.empty() && heights[st.top()] >= current_height) {
                    int idx = st.top();
                    st.pop();
                    int psi = st.empty() ? -1 : st.top();
                    int ans = (j - psi - 1) * heights[idx];
                    maxans = max(ans, maxans);
                }
                st.push(j);              
            }
            maxx = max(maxx, maxans);
        }

        return maxx;
    }
};
