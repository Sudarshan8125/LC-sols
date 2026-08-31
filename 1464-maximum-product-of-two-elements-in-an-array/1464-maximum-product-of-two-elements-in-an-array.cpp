class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int maxi = INT_MIN;
        int smaxi = INT_MIN;

        for(auto num:nums){
            if(num>maxi){
                smaxi = maxi;
                maxi = num;
            }
            else{
                smaxi = max(num,smaxi);
            }
        }

        return (maxi-1) * (smaxi-1);
    }
};