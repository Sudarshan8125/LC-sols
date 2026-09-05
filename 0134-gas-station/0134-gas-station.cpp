class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int gast = accumulate(gas.begin(),gas.end(),0);
        int tcost = accumulate(cost.begin(),cost.end(),0);

        if(gast<tcost) return -1;
        
        int total = 0;
        int idx = -1;
        for(int i = 0; i<n; i++){
            total += gas[i] - cost[i];
            if(total>=0 && idx == -1) idx = i;
            else if(total<0){
                total = 0;
                idx = i+1;
            }
        }
        if(idx!=-1 && idx<n) return idx;
        return -1;
    }
};