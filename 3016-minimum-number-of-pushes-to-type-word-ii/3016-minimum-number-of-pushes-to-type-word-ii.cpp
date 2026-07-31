class Solution {
public:
    int minimumPushes(string word) {
        vector<int> frequencies(26,0);
        for(auto ch:word){
            frequencies[ch-'a']++;
        }

        sort(frequencies.rbegin(),frequencies.rend()); //highest first //so to know whom to process first
        int types = 0,cost = 0;
        for(int i=0;i<26;i++){
            if(i%8 == 0) cost++;
            types += cost * frequencies[i];
        }
        return types;
    }
};