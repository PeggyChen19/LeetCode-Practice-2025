class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - k, ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid + k < arr.size() && x - arr[mid] > arr[mid + k] - x) { // go right
                left = mid + 1;
            } else { // go left (this condition includes possible ans)
                ans = mid;
                right = mid - 1;
            }
        }
        return vector<int>(arr.begin() + ans, arr.begin() + ans + k);
    }
};
/*
1. find index of x (or nearest point) from the sorted array -> binary search
2. check the nearest nums in two directions (go to front / go to back)
3. store in two vector and reverse it and combine

Improvement: We can directly find the start index of result use binary search
Possible start index range: [0, arr.size - k]
abs(x - arr[mid]) > abs(x - arr[mid+k]): go right
else: go left & update ans (might include possible ans)
*/