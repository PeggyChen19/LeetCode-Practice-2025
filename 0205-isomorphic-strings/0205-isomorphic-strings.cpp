class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> s2t(256, -1);
        vector<int> t2s(256, -1);
        for (int i = 0; i < s.size(); i++) {
            char a = s[i], b = t[i];
            if (s2t[a] == -1 && t2s[b] == -1) {
                s2t[a] = b;
                t2s[b] = a;
            } else if (s2t[a] != b || t2s[b] != a) return false;
        }
        return true;
    }
};
/*
use 2 vectors to record the mapping
space: O(1) -> limited amount of char
*/