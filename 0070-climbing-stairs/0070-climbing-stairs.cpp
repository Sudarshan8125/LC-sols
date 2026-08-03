class Solution {
public:
    int climbStairs(int n) {
        //converting to tabulation
        //as well as optiizing space
        int prev2 = 1; //from base cases to the top
        int prev = 1;
        int curr = prev;

        for(int i = 2;i<=n;i++){
            curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return curr;
    }
};