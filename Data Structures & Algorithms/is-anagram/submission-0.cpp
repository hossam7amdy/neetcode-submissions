class Solution {
   public:
    bool isAnagram(string s, string t) {
        vector<int> count = vector(26, 0);

        for (int i = 0; i < s.size(); i++) count[s[i] - 'a']++;
        for (int i = 0; i < t.size(); i++) count[t[i] - 'a']--;

        for (int i = 0; i < count.size(); i++) {
            if (count[i] != 0) return false;
        }

        return true;
    }
};

/*
s = "racecar"
r=2
a=2
c=2
e=1

------
t = "carrace"
r=2
a=2
c=2
e=1


freq = [26]

*/