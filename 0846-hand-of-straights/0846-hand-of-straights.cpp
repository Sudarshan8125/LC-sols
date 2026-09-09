class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize!=0) return false;

        map<int,int> freq;
        for(auto it:hand) freq[it]++;

        int tot_groups = n/groupSize;
        while(tot_groups){
            auto it = freq.begin();
            int key = it->first;
            int cnt = 0;
            while(cnt<groupSize){
                if(freq.find(key) == freq.end()) return false;
                freq[key]--;
                if(freq[key] == 0) freq.erase(key);
                key++;
                cnt++;
            }
            if(cnt < groupSize) return false;
            tot_groups--;
        }
        return true;
    }
};