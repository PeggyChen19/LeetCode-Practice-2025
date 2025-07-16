class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> rows(numRows, "");
        int i = 0;
        bool goDown = false;
        for (char& ch: s) {
            rows[i].push_back(ch);
            if (i == 0 || i == numRows - 1) goDown = !goDown;
            i += goDown ? 1 : -1;
        }
        string result = "";
        for (string& row : rows) result += row;
        return result;
    }
};
/*
1     7
2   6 8
3 5   9
4

1. use vector<string> to record each row
2. concatenate the vector to get the answer
*/