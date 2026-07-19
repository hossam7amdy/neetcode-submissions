class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> y;
        for (int j = 0; j < nums.size(); j++) {
            int complement = target - nums[j];
            if (y.count(complement)) {
                return {y[complement], j};
            }
            y[nums[j]] = j;
        }
        return {-1, -1};
    }
};

/*
nums = [3,4,5,6] target = 7

complement = target - current = y

if(y) in complement, then I am the x
if not, then I might be a future x

[<3,0>, <4,1>]
-----
*/