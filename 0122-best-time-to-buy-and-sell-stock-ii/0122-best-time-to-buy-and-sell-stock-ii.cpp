class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //get every hike in profit
        int n=prices.size();
        int prof=0;
        for(int i=1;i<n;i++){
            prof += prices[i]-prices[i-1] > 0 ? prices[i]-prices[i-1]:0;
        }
        return prof;
    }
};