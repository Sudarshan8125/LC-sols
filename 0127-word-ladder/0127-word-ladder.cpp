class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int l = beginWord.size();
        unordered_map<string,int> vis; //make string as node states
        unordered_set<char> adj[l]; //where can u nevigate to from any node
        for(auto it:wordList){
            vis[it] = 0;
            for(int i=0;i<l;i++){
                adj[i].insert(it[i]);
            }
        }

        queue<string> q;
        q.push(beginWord);
        int len = 1;
        while(!q.empty()){
            int size = q.size();
            
            for(int i=0;i<size;i++){
                string curr = q.front();
                q.pop();

                for(int i=0;i<l;i++){
                    for(auto ch:adj[i]){
                        string temp = curr;
                        temp[i] = ch;

                        if(temp == endWord) return len+1;

                        auto it = vis.find(temp);
                        if(it!=vis.end() && it->second!=1){ // if its a valid word
                            it->second = 1;
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