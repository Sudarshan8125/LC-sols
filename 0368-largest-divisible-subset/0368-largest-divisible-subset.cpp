class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<int> dp(n,1); //for length of subset
        vector<int> hash(n,0);
        int maxlen = 1, last = 0;
        for(int i=0; i<n; i++){
            hash[i] = i;
            for(int j=0; j<i; j++){

                if(nums[i]%nums[j] == 0 && dp[j]+1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if(dp[i] > maxlen){
                maxlen = dp[i];
                last = i;
            }
        }

        vector<int> temp;
        temp.push_back(nums[last]);
        while(hash[last]!=last){
            last = hash[last];
            temp.push_back(nums[last]);
        }

        reverse(temp.begin(),temp.end());

        return temp;
    }
};