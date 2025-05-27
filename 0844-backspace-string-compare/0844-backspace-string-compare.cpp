class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int sInd = s.size() - 1;
        int tInd = t.size() - 1;
        while (sInd >= 0 || tInd >= 0) {
            removeChar(s, sInd);
            removeChar(t, tInd);
            if (sInd >= 0 && tInd >= 0 && s[sInd] != t[tInd]) {
                return false;
            } else if ((sInd >= 0 && tInd < 0) || (sInd < 0 && tInd >= 0)) {
                return false;
            }
            sInd--;
            tInd--;
        }
        return (sInd == tInd);
    }
private:
    void removeChar(string& str, int& ind) {
        int del = 0;
        while (ind >= 0) {
            if (str[ind] == '#') {
                del++;
                ind--;
            } else if(del > 0) {
                del--;
                ind--;
            } else {
                break; // remain this char
            }
        }
    }
};
/*
Go through s & t from end to begin
Record the number of # and ignore corresponding element
*/