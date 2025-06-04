class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> smaller, bigger;
        int ind = binarySearch(arr, x);
        int left = ind;
        int right = ind + 1;
        while (k > 0) {
            if (left >= 0 && right < arr.size()) { // both valid -> compare
                int lDis = x - arr[left];
                int rDis = arr[right] - x;
                if (lDis <= rDis) {
                    smaller.push_back(arr[left]);
                    left--;
                } else {
                    bigger.push_back(arr[right]);
                    right++;
                }
            } else if (left >= 0) {
                smaller.push_back(arr[left]);
                left--;
            } else {
                bigger.push_back(arr[right]);
                right++;
            }
            k--;
        }
        reverse(smaller.begin(), smaller.end());
        smaller.insert(smaller.end(), bigger.begin(), bigger.end());
        return smaller;
    }
private:
    int binarySearch(vector<int>& arr, int target) {
        int result = -1, left = 0, right = arr.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) { // go right
                result = mid;
                left = mid + 1;
            } else { // go left
                right = mid - 1;
            }
        }
        return result; // the nearest smaller index
    }
};
/*
1. find index of x (or nearest point) from the sorted array -> binary search
2. check the nearest nums in two directions (go to front / go to back)
3. store in two vector and reverse it and combine
*/