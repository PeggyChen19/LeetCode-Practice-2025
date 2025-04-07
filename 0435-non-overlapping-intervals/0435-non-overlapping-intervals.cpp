class Solution {
private:
    static bool cmp_end(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), cmp_end);
        int ans = 0;
        int pre_interval_end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < pre_interval_end) { // overlapping
                ans++; // delete cur -> don't need to update pre
            } else {
                pre_interval_end = intervals[i][1]; // update pre
            }
        }
        return ans;
    }
};

/*
[pre_interval]
        [cur_interval]
-
sort intervals by end
create int ans = 0
create int pre_interval_end = intervals[0][1]
go through all intervals except the first one
    if prev & cur overlap
        ans++ // delete cur
    else
        pre = cur // update pre
-
Time: O(nlogn), Space: O(1)
*/