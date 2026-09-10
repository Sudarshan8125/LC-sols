class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;

        for(int i = 0; i<n; i++){
            while(!st.empty() && st.top()>0 && asteroids[i]<0 && st.top() < abs(asteroids[i])) st.pop();
            if(!st.empty() && st.top()>0 && asteroids[i]<0 && st.top() == abs(asteroids[i])){
                st.pop();
                continue;
            }
            if(st.empty()) st.push(asteroids[i]);
            else if(st.top() * asteroids[i] >0) st.push(asteroids[i]);
            else if(st.top()<0 && asteroids[i] >0) st.push(asteroids[i]);
        }

        int size = st.size();
        vector<int> ans(size);
        int i = size - 1;

        while(!st.empty()){
            ans[i] = st.top();
            st.pop();
            i--;
        }
        return ans;
    }
};