class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty() || strs[0].empty()) {
            return "";
        }
        int commonInd = strs[0].size();
        for (int i = 1; i < strs.size(); i++) {
            for (int j = 0; j < commonInd; j++) {
                if (strs[0][j] != strs[i][j]) {
                    commonInd = j;
                    break;
                }
            }
            if (commonInd == 0) {
                return "";
            }
        }
        return strs[0].substr(0, commonInd);
    }
};
/*
Use a pointer to record the index of longest common prefix
-> Point at the end of strs[0]
Go through remaining strs, update the pointer
*/