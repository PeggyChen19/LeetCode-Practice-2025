class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string result = "";
        int n = s.size();

        // top row
        int i = 0;
        while (i < n) {
            result += s[i];
            i += (numRows - 1) * 2;
        }
        // middle rows
        for (i = 1; i < numRows - 1; i++) {
            int j = i;
            while (j < n) {
                result += s[j];
                int mid = j + (numRows - 1 - i) * 2;
                if (mid >= n) break;
                result += s[mid];
                j += (numRows - 1) * 2;
            }
        }
        // bottom row
        i = numRows - 1;
        while (i < n) {
            result += s[i];
            i += (numRows - 1) * 2;
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

Brute force: use an additional vector<vector<char>> size numRows
Improvement: try to derive the formula

for top row & bottom rows: (only have col)
1. start with i
2. update result with i
3. i += (numRows - 1) * 2
4. loop 2~3

for middle rows i: (have mid & col)
1. start with i (j = i) 
2. update result with j
3. mid = j + (numRows - 1 - i) * 2
4. update result with mid
5. i += (numRows - 1) * 2
6. loop 2~5
*/