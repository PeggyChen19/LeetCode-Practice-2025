class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs[0].size() == 0) {
            return "";
        }
        int commonInd = strs[0].size() - 1;
        for (int i = 1; i < strs.size(); i++) {
            for (int j = 0; j <= commonInd; j++) {
                if (strs[0][j] != strs[i][j]) {
                    commonInd = j - 1;
                    break;
                }
            }
        }
        return strs[0].substr(0, commonInd + 1);
    }
};
/*
Use a pointer to record the index of longest common prefix
-> Point at the end of strs[0]
Go through remaining strs, update the pointer
*/