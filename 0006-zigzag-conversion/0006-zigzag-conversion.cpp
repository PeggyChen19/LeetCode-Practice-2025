class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string result = "";
        int n = s.size();
        for (int i = 0; i < numRows; i++) {
            int j = i;
            while (j < n) {
                result += s[j];
                int mid = j + (numRows - 1 - i) * 2;
                if (i != 0 && i != numRows - 1 && mid < n) {
                    result += s[mid];
                }
                j += (numRows - 1) * 2;
            }
        }
        return result;
    }
};
/*
0     6
1   5 7
2 4   8
3     9
  ^^^ ^
  mid col

Brute force: use an additional vector<vector<char>>, size: numRows
Improvement: try to derive the formula
for each row i:
1. start with i (j = i) 
2. result += j
3. mid = j + (numRows - 1 - i) + (numRows - 1 - i)
4. if middile row: result += mid
5. i += numRows + numRows - 2
6. loop 2~5
*/