class Solution {
public:
    bool isMatch(string s, string p) {
        return checkMatch(0, s, 0, p);
    }
private:
    bool checkMatch(int i, string& s, int j, string& p) {
        int m = s.size(), n = p.size();
        while (i < m && j < n) {
            if (j < n - 1 && p[j + 1] == '*') {
                // skip _*, go to next pattern
                bool skipStar = checkMatch(i, s, j + 2, p); 
                // if can match: go to next i, butkeep this pattern
                bool useStar = (p[j] == '.' || s[i] == p[j]) ? checkMatch(i + 1, s, j, p) : false;
                return skipStar || useStar;
            } else if (p[j] == '.' || s[i] == p[j]) { // matched
                i++;
                j++;
            } else { // not matched
                return false;
            }
        }
        while (j < n - 1 && p[j + 1] == '*') {
            j += 2;
        }
        return (i == m && j == n);
    }
};