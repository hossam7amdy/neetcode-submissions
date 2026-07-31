class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> exist(nums.begin(), nums.end());

        int longest = 0;
        for (const int num : nums) {
            if (!exist.count(num - 1)) {
                int curLen = 1;
                int node = num;
                while (exist.count(node + 1)) {
                    curLen++;
                    node++;
                }
                longest = max(longest, curLen);
            }
        }
        return longest;
    }
};

/*
Example 1:
[2,20,4,10,3,4,5]
[2,3,4,5,10,20] = 4

[2] -> [3]
[3] -> [4]
[4] -> [5]

Example 2:
[0,3,2,5,4,6,1,1]
[0,1,1,2,3,4,5,6]
*/
