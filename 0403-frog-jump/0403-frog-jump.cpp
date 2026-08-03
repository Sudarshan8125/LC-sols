class Solution {
public:

    bool f(int x,int step,int l,unordered_set<int>& st,unordered_map<int,unordered_set<int>>& failed_states){
        if(x >= l){
            if(x==l) return true;
            else return false;
        }
        
        if(failed_states[x].count(step)) return false;

        if(st.count(x)==0) return false;//shits water

        for(int next = step-1; next<=step+1; next++){
            if(next>0){
                if(f(x+next,next,l,st,failed_states) == true) return true;
            }
        }
        
        failed_states[x].insert(step);
        return false;
    }
    bool canCross(vector<int>& stones) {
        // we need to check all possible ways becuase if any jump strategy takes us to end off we goo 
        int n = stones.size();
        unordered_set<int> st;
        unordered_map<int, unordered_set<int>> failed_states;

        for(int i = 0;i<n;i++){
            st.insert(stones[i]);
        }
        int l = stones[n-1];
        return f(stones[0],0,l,st,failed_states);
    }
};