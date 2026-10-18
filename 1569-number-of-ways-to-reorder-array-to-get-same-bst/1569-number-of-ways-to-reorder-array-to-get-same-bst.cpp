class Solution {
public:
    int MOD = 1e9 + 7;
    vector<vector<int>> PT;

    int solve(vector<int>& nums){
        int n = nums.size();
        if (n <= 2) return 1;

        vector<int> left_array;
        vector<int> right_array;

        int root = nums[0];

        for(int i = 1; i<n; i++){
            if(root > nums[i]) left_array.push_back(nums[i]);
            else right_array.push_back(nums[i]);
        }

        long long l = solve(left_array);
        long long  r = solve(right_array);

        long long z = PT[n-1][left_array.size()];

        return (((l * r) % MOD) * z) % MOD;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        PT.resize(n);

        for(int i = 0; i<n; i++){
            PT[i] = vector<int>(n+1,1);
            for(int j = 1; j<i; j++){
                PT[i][j] = (PT[i-1][j] + PT[i-1][j-1]) % MOD;
            }
        }

        return (solve(nums) - 1) % MOD;
    }
};