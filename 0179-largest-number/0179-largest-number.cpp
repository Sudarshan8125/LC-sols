class Solution {
public:
    static bool comp(const string&a, const string&b){
        return a+b > b+a;
    }

    string largestNumber(vector<int>& nums) {
        
        vector<string> sorted;
        for(auto it:nums) sorted.push_back(to_string(it));

        sort(sorted.begin(),sorted.end(),comp);

        if(!sorted.empty() && sorted[0] == "0"){
            return "0";
        }
        
        string res = "";
        for(auto s:sorted) res+=s;
        return res;
    }
};