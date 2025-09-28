class NumMatrix {
private:
    vector<vector<int>> regionSum;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        regionSum = vector<vector<int>>(m, vector<int>(n, 0));
        for (int i = 0; i < matrix.size(); i++) {
            int prefixSum = 0;
            for (int j = 0; j < matrix[0].size(); j++) {
                prefixSum += matrix[i][j];
                if (i == 0) {
                    regionSum[i][j]= prefixSum;
                } else {
                    regionSum[i][j] = regionSum[i - 1][j] + prefixSum;
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int top = (row1 - 1 < 0) ? 0 : regionSum[row1 - 1][col2];
        int left = (col1 - 1 < 0) ? 0 : regionSum[row2][col1 - 1];
        int topLeft = ((row1 - 1 < 0) || (col1 - 1 < 0)) ? 0 : regionSum[row1 - 1][col1 - 1];
        return regionSum[row2][col2] - top - left + topLeft;
    }
};

/*
Time Complexity -> O(1)
For one row -> intervalSum[i, j] = prefixSum[j] - prefixSum[i]
2 dimension prefix sum? (topLeft - bottomRight)?

1. record each row prefixSum = prefixSum[i-1] + nums[i] -> O(n*n)
2. record prefix regionSum[i][j] = regionSum[i-1][j] + prefixSum[j] -> O(n*m)

result[row1][col1][row2][col2]
= regionSum[row2][col2] - regionSum[row1 - 1][col2] - regionSum[row2][col1 - 1] + regionSum[row1 - 1][col1 - 1]
*/