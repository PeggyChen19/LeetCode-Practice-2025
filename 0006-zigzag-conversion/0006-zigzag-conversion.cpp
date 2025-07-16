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
                int mid = j + (numRows - i - 1) + (numRows - i - 2) + 1;
                if (mid >= n) break;
                result += s[mid];
                j += numRows + numRows - 2;
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