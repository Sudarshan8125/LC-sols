#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // 1. Sort the array so that closest values are adjacent
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int l = 0, r = 0;
        int maxlen = 0;
        long long sum = 0; // Use long long to prevent overflow during sum accumulation

        while (r < n) {
            sum += nums[r];

            // 2. nums[r] is always the maximum in the window [l, r] because it's sorted
            while ((long long)nums[r] * (r - l + 1) - sum > k) {
                sum -= nums[l];
                l++;
            }
            
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};
