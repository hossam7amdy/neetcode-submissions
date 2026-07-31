class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        unordered_set<int> exist(nums.begin(), nums.end());
        unordered_set<int> visited;

        int res = 1;
        for (int i = 0; i < nums.size(); i++) {
            int node = nums[i];
            if (visited.count(node)) continue;

            int curLen = 1;
            while (exist.count(node + 1)) {
                visited.insert(node);
                curLen++;
                node++;
            }
            res = max(res, curLen);
        }
        return res;
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
