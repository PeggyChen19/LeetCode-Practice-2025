class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty() || strs[0].empty()) return "";
        int prefix = strs[0].size();
        for (int i = 1; i < strs.size(); i++) {
            int size = strs[i].size();
            prefix = min(prefix, size);
            for (int j = 0; j < prefix; j++) {
                if (strs[0][j] != strs[i][j]) {
                    prefix = j;
                    break;
                }
            }
        }
        return strs[0].substr(0, prefix);
    }
};