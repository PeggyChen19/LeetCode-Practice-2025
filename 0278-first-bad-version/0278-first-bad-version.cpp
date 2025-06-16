// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
class Solution {
public:
    int firstBadVersion(int n) {
        int result = -1;
        int left = 1, right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) { // go left
                result = mid; // possible result
                right = mid - 1;
            } else { // go right
                left = mid + 1;
            }
        }
        return result;
    }
};
/*
Versions: [f f f "t" t t t]
Target: find the first "t" -> binary search O(logn)
*/