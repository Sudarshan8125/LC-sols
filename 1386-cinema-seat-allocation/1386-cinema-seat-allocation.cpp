class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        unordered_map<int,unordered_set<int>> res;
        for(const auto& it:reservedSeats){
            int r = it[0], s = it[1];
            res[r].insert(s);
        }
        int np = 0;
        for(const auto& it:res){
            auto[row,reserved] = it;
            bool left_free = !reserved.count(2) && !reserved.count(3) 
                                && !reserved.count(4) && !reserved.count(5);

            bool right_free = !reserved.count(4) && !reserved.count(5) 
                                && !reserved.count(6) && !reserved.count(7);

            bool middle_free = !reserved.count(6) && !reserved.count(7) 
                                && !reserved.count(8) && !reserved.count(9);
            
            if(!middle_free){
                np++;
                if(!left_free && !right_free) np++;
            }
            else if(!left_free) np++;
            else if(!right_free) np++;
        }
        return n*2 - np;
    }
};