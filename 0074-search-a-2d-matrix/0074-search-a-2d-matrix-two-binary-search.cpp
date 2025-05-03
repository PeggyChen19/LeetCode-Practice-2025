class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> rowHead(m);
        for (int i = 0; i < m; i++) {
            rowHead[i] = matrix[i][0];
        }
        int rowInd = binarySearch(rowHead, 0, m-1, target);
        if (rowInd >= m || matrix[rowInd][0] != target) { // nearest bigger
            rowInd--;
        }
        if (rowInd < 0) { // there is no nearest smaller
            return false;
        }
        int colInd = binarySearch(matrix[rowInd], 0, n-1, target);
        return (colInd >= n || matrix[rowInd][colInd] != target) ? false : true;
    }
private: 
    int binarySearch(vector<int>& vec, int left, int right, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (vec[mid] < target) { // go right
                left = mid + 1;
            } else if (vec[mid] > target) { // go left
                right = mid - 1;
            } else {
                return mid;
            }
        }
        return left;
    }
};
/*
Binary search1: find the possbile row
Binary search2: find the target in the possible row
1:
Goal: find rowHead == target OR rowHead nearest to target but smaller
if we return left -> the nearest larger one
so we can use left-1 represent the nearest smaller one
2:
ending condition: matrix[i][j] == target
*/