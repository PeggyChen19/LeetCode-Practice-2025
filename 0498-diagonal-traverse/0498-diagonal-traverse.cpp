class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> result;
        int i = 0, j = 0;
        bool upRight = true;
        while (i < m && j < n) {
            result.push_back(mat[i][j]);
            if (upRight) {
                if (i - 1 >= 0 && j + 1 < n) { // valid
                    i--;
                    j++;
                } else { // change direction
                    upRight = false;
                    if (j + 1 < n) j++;
                    else i++;
                }
            } else {
                if (i + 1 < m && j - 1 >= 0) { // valid
                    i++;
                    j--;
                } else {
                    upRight = true;
                    if (i + 1 < m) i++;
                    else j++;
                }
            }
        }
        return result;
    }
};
/*
two kinds of diagonal order (i, j) means the current cell
1. go up right: (i-1, j+1)
2. go down left: (i+1, j-1)
we will switch between 1 and 2

when to switch? there is no next node on the order
how to know the next start pooint?
case 1. go to (i, j+1), if not exist, go to (i+1, j)
case 2. go to (i+1, j), if not exist, go to (i, j+1)

1 2 3
4 5 6
7 8 9

1 2 3 4
5 6 7 8
9 0 1 2
*/