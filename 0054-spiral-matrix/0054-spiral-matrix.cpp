class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;
        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++) { // left to right
                ans.push_back(matrix[top][i]);
            }
            top++;
            for (int i = top; i <= bottom; i++) { // top to down
                ans.push_back(matrix[i][right]);
            }
            right--;
            if (top > bottom) break;
            for (int i = right; i >= left; i--) { // right to left
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
            if (left > right) break;
            for (int i = bottom; i >= top; i--) { // down to top
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
        return ans;
    }
};
/*
boundary: 
top~bottom: 0~m, left~right: 0~n

moving directions:
1. left to right
top++
2. top to down
right--
3. right to left
bottom--
4. down to top
left++
*/