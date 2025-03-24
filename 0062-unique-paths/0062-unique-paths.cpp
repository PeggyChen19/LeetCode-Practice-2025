class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> record(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                record[j] = record[j] + record[j - 1]; // cell[i][j] = cell[i-1][j] + cell[i][j-1]
            }
        }
        return record[n - 1];
    }
};

/*
1. can only "down" or "right" -> for current cell, it must from "up" or "left"
2. f(a, b) = f(a-1, b) + f(a, b-1)
3. f(0, i) = f(i, 0) = 1
4. originally, we need m*n lookup table
    however, we can improve the space usage
    after finishing calculate row i, we can drop row i-1 (won't use it anymore) and only keep row i for row i+1
    and for column, we only need to record the j-1 (not all previous left columns)
    -> we only need to record one row and one left value
    -> 走到 cell[i][j] 之前，record[j] 紀錄的是 cell[i-1][j] 的紀錄，走過之後，更新成 cell[i][j]
       值得注意的是新更新的 cell[i][j] 剛好是 cell[i][j+1] 需要的 left，所以我們也不需要額外存 left，直接用前一個的 record[j-1] 即可
5. use double for loop to implement
*/