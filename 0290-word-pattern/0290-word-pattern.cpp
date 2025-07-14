class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> strMapping(26, "");
        unordered_map<string, char> charMapping;

        int pInd = 0, sInd = 0;
        while (sInd < s.size()) {
            string word = "";
            while (sInd < s.size() && s[sInd] != ' ') {
                word += s[sInd];
                sInd++;
            }
            sInd++;
            if (strMapping[pattern[pInd] - 'a'] == "" && !charMapping.count(word)) { // haven't had mapping
                charMapping[word] = pattern[pInd];
                strMapping[pattern[pInd] - 'a'] = word;
            } else if (strMapping[pattern[pInd] - 'a'] == "" || 
                       !charMapping.count(word) || 
                       charMapping[word] != pattern[pInd]) { // have incorrect mapping
                return false;
            }
            pInd++;
        }
        return pInd == pattern.size();
    }
};
/*
vector<string> & unordered_map<string, char> to record the mapping
go through s & pattern, try to match the mapping
*/