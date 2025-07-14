class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charToStr;
        unordered_map<string, char> strToChar;
        int pInd = 0;
        istringstream iss(s);
        string word;
        while(getline(iss, word, ' ')) {
            if (pInd >= pattern.size()) return false;

            char p = pattern[pInd];
            if (charToStr.count(p) && charToStr[p] != word) return false;
            if (strToChar.count(word) && strToChar[word] != p) return false;
            // do the mapping
            charToStr[p] = word;
            strToChar[word] = p;
            pInd++;
        }
        return pInd == pattern.size();
    }
};
/*
two unordered_map to record the bijection
go through s & pattern, try to match the mapping
*/