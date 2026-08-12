class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        
        // Step 1: Calculate the sum of the longest sequential prefix
        for (int r = 1; r < n; r++) {
            if (nums[r] == nums[r - 1] + 1) {
                sum += nums[r];
            } else {
                break; // A prefix must start at index 0; stop as soon as it breaks
            }
        }
        
        // Step 2: Store all array elements in a hash set for O(1) lookups
        unordered_set<int> st(nums.begin(), nums.end());
        
        // Step 3: Find the smallest missing integer >= prefix sum
        while (st.count(sum)) {
            sum++;
        }
        
        return sum;
    }
};
