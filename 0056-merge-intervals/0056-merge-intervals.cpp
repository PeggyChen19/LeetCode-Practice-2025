class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans = {intervals[0]};
        for (int i = 1; i < intervals.size(); i++) {
            if (ans.back()[1] < intervals[i][0]) { // non-overlapping
                ans.push_back(intervals[i]);
            } else { // overlapping -> update ans.back()[1]
                // don't need to update start because intervals are sorted
                ans.back()[1] = max(intervals[i][1], ans.back()[1]);
            }
        }
        return ans;
    }
};

/*
sort intervals
go through all intervals except the last one
    if (i).end < (i+1).start // non-overlapping
        append(i)
    else
        merge 2 intervals (star = min, end = max)
        store merged interval to i+1
insert the last one
*/