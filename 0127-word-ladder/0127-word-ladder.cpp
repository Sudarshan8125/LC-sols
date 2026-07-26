class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int l = beginWord.size();

        unordered_set<string> st; //make string as node states 
        for(auto it:wordList){
            st.insert(it);
        }
        if (st.find(endWord) == st.end()) return 0;

    
        queue<string> q;
        q.push(beginWord);
        int len = 1;

        while(!q.empty()){
            int size = q.size();
            
            for(int i=0;i<size;i++){
                string curr = q.front();
                q.pop();

                // Base check: If we reached the target, return current sequence length
                if (curr == endWord) return len;

                // Step 2: Try changing every character position
                for (int j = 0; j < l; j++) {
                    string temp = curr;
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        temp[j] = ch;
                        if (st.find(temp) != st.end()) { //if valid
                            st.erase(temp); 
                            q.push(temp);
                        }
                    }
                }
            }
            len++;
        }
        
        return 0;
    }
};