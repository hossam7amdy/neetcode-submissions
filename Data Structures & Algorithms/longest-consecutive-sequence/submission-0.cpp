class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        unordered_set<int> exist(nums.begin(), nums.end());
        unordered_map<int, int> graph;

        for (int i = 0; i < nums.size(); i++) {
            if (exist.count(nums[i] - 1)) {
                graph[nums[i] - 1] = nums[i];
            }
        }

        int res = 1;
        unordered_set<int> visited;
        for (const auto& [key, value] : graph) {
            if (visited.count(key)) continue;

            int len = 1;
            for (int node = key; graph.count(node); node = graph[node]) {
                ++len;
                visited.insert(node);
            }
            res = max(res, len);
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
