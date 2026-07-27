class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(int i = 0; i < strs.size(); i++) {
            string sorted = strs[i];
            sort(sorted.begin(), sorted.end());
            if(mp.count(sorted)) {
                mp[sorted].push_back(strs[i]);
            } else {
                mp[sorted] = {strs[i]};
            }
        }

        vector<vector<string>> result;
        result.reserve(mp.size());
        for(const auto& [key, value] : mp) {
            result.push_back(value);
        }
        return result;
    }
};

/*
strs = ["act","pots","tops","cat","stop","hat"]

[act]: [act, cat]
[]

*/