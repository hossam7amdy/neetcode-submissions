class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        vector<vector<int>> bucket(nums.size() + 1);

        for(int n : nums) {
            freq[n] = 1 + freq[n];
        }
        for(const auto& [val, fr] : freq) {
            bucket[fr].push_back(val);
        }

        vector<int> result;
        for(int i = bucket.size() - 1; i >= 0; i--) {
            for(int val : bucket[i]) {
                result.push_back(val);
                if(result.size() == k) {
                    return result;
                }
            }
        }
        return result;
    }
};
