class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int possibleMax = 0;
        for (int pile : piles) {
            possibleMax = max(possibleMax, pile);
        }
        int left = 1, right = possibleMax;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int hours = calculateHours(piles, mid, h);
            if (hours > h) { // go right
                left = mid + 1;
            } else { // hours <= h: go left
                right = mid - 1;
            }
        }
        return left;
    }
    int calculateHours(vector<int>& piles, int k, int h) {
        int hours = 0;
        for (int pile : piles) {
            hours += (pile / k + (pile % k != 0)); // round up
            if (hours > h) { // early return
                return hours;
            }
        }
        return hours;
    }
};
/*
length <= h
for each pile, at least needs one hour to eat
possible ans range: 1 ~ max(piles)
in this range, we can calculate the needed hours
use binary search to speed up
find the min which needed hour == h
speed: small ---------> big
hours: big ---hhhh--> small
              ^
we want to find the first h

Time Complexity: O(nlog(max(piles)))

can we divide and conquer this problem?
there is no optimal substructure

*/