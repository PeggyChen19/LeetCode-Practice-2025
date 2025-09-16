class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        vector<int> frequent(26, 0);
        for (int i = 0; i < s.size(); i++) {
            frequent[s[i]-'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            frequent[t[i]-'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (frequent[i] != 0) {
                return false;
            }
        }
        return true;
    }
};