class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1, zeroCount = 0;
        for (const auto& num : nums) {
            if (num == 0) {
                zeroCount++;
            } else {
                prod *= num;
            }
        }
        if (zeroCount > 1) {
            return vector<int>(nums.size(), 0);
        }
        vector<int> res(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            if (zeroCount) {
                res[i] = nums[i] == 0 ? prod : 0;
            } else {
                res[i] = prod / nums[i];
            }
        }
        return res;
    }
};

/*
1. O(n^2)
[1,2,4,6]
[...]

2. O(n) + using division operator
[1,2,4,6]
[48,24,12,8]

[-1,0,1,2,3] prod = -6, zeroCount = 1
[0,-6,0,0,0]

3. O(n) without using division operator
[1,2,4,6]
prefix = [1,2,8,48]
suffix = [48,48,24,6]

[1,2,4,6]

[1,2,8,48]
[48,48,24,6]

[48,24,12,8]
*/