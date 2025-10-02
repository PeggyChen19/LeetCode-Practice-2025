class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int i = 0; i < numRows; i++) {
            vector<int> cur(i + 1, 1); // index 0 ~ i
            for (int j = 1; j < i; j++) {
                cur[j] = result[i - 1][j - 1] + result[i - 1][j];
            }
            result.push_back(cur);
        }
        return result;
    }
};
/*
    1
   1 1
  1 2 1
for each row
    head & tail: 1
    row[i]: upperRow[i - 1] + upperRow[i]
*/