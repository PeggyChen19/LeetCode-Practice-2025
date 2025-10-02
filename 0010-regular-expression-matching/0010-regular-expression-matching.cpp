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
                bool skipStar = checkMatch(i, s, j + 2, p); // skip _*, go to next pattern
                bool useStar = (p[j] == '.' || s[i] == p[j]) ? checkMatch(i + 1, s, j, p) : false; // if can match, keep this pattern
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
/*
s[i], p[j]
recursion(i, j)
    while not reaching end
        if (p[j + 1] == *)
            recursion(i, j+2) // zero
            recursion(i+1, j) // one or more
        if (p[j] == .) // directly match a random char
            i++
            j++
        if not match
            return false
    return (both finish)
*/