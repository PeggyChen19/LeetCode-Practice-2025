class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> strsMap;
        vector<vector<string>> ans;
        for (auto str : strs) {
            array<int, 26> charCount = {0};
            for (auto ch : str) {
                charCount[ch-'a']++;
            }
            string key;
            for (auto ch : charCount) {
                key = key + to_string(ch) + "#";
            }
            (strsMap[key]).push_back(str);
        }
        for (auto it : strsMap) {
            ans.push_back(it.second);
        }
        return ans;
    }
};

