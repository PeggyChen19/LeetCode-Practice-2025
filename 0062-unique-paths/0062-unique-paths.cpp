class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> record(n, 1);
        int left = 1;
        for (int i = 1; i < m; i++) {
            left = 1;
            for (int j = 1; j < n; j++) {
                left = record[j] + left;
                record[j] = left;
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
    after finishing calculate row i, we can drop row i-1 and only keep row i for row i+1
    and for column, we only need to record the j-1 (not all previous left columns)
    -> we only need to record one row and one left
5. use double for loop to implement
*/