class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();

        stack<int> st;
        stack<int> asterisk;

        for(int i = 0;i<n;i++){
            if(s[i] == '(') st.push(i);
            if(s[i] == ')'){
                if(!st.empty()) st.pop();
                else if(!asterisk.empty()){
                    asterisk.pop();
                }
                else return false;
            }
            if(s[i] == '*') asterisk.push(i);
        }

        while(!st.empty()){
            if(!asterisk.empty() && st.top()<asterisk.top()){
                st.pop();
                asterisk.pop();
            }
            else break;
        }

        return st.empty();
    }
};