class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int result = 0, left = 0, right = n - 1;
        while (left < right) {
            result = max(result, (right - left) * min(height[left], height[right]));
            if (left < right) {
                left++;
            } else {
                right--;
            }
        }
        return result;
    }
};
/*
Max area: ( x[r] - x[l] ) * min(y[r], y[l])
Greedy + Two pointers
1. let x be max (left & right point to the start & end)
2. left++ or right-- to get a higher min(y)
3. Try all possible better solutions and get the global best solution
*/