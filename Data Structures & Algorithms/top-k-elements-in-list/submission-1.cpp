class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        vector<pair<int,int>> pair;
        for(const auto& [key, value] : freq) {
            pair.push_back({value, key});
        }

        sort(pair.begin(), pair.end());

        vector<int> result;
        for(int i = pair.size() - 1; i >= 0 && k > 0; i--, k--){
            result.push_back(pair[i].second);
        }

        return result;
    }
};

/*
nums = [1,2,2,3,3,3], k = 2

1 = 1
2 = 2
3 = 3

*/