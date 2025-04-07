class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }
        sort(intervals.begin(), intervals.end());
        int ans = 0;
        int pre_interval_end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < pre_interval_end) { // overlapping
                ans++;
                pre_interval_end = min(intervals[i][1], pre_interval_end);
            } else {
                pre_interval_end = intervals[i][1];
            }
        }
        return ans;
    }
};

/*
sort intervals
create int ans = 0
create vector pre_interval = intervals[0]
go through all intervals except the first one
    if prev & cur overlap
        ans++
        update prev to the one with smaller end
    else
        pre = cur

[pre_interval]
        [cur_interval]
*/