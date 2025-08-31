class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mapping;
        unordered_set<char> mapped;
        for (int i = 0; i < s.size(); i++) {
            if (!mapping.count(s[i]) && !mapped.count(t[i])) {
                mapping[s[i]] = t[i];
                mapped.insert(t[i]);
            } else if (!mapping.count(s[i]) || mapping[s[i]] != t[i]) return false;
        }
        return true;
    }
};
/*
use unorderd_map to record the mapping
space: O(n) -> limited amount of char
*/