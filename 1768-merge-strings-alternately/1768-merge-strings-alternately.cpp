class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int p1 = 0, p2 = 0;
        int m = word1.size(), n = word2.size();
        string result;
        while (p1 < m && p2 < n) {
            result.push_back(word1[p1]);
            p1++;
            result.push_back(word2[p2]);
            p2++;
        }
        while (p1 < m) {
            result.push_back(word1[p1]);
            p1++;
        }
        while (p2 < n) {
            result.push_back(word2[p2]);
            p2++;
        }
        return result;
    }
};
/*
two separated pointers, p1 & p2
move p1 or p2 forward each round
*/