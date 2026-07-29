class Solution {
   public:
    string encode(vector<string>& strs) {
        string res = "";
        for (const auto& str : strs) {
            int size = str.size();
            if (size < 10) {
                res += "00";
            } else if (size < 100) {
                res += "0";
            }
            res += to_string(size);
            res += str;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        for (int i = 0; i < s.size(); i += 3) {
            string lenLiteral = s.substr(i, 3);
            int size = stoi(lenLiteral);
            res.push_back(s.substr(i + 3, size));
            i += size;
        }
        return res;
    }
};

/*
["Hello","World"] => 005Hellow005World => ["Hello","World"]

[""] => 000 => [""]

*/