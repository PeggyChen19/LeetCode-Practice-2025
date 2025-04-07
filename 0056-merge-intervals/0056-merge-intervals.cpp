class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < n - 1; i++) {
            if (intervals[i][1] < intervals[i+1][0]) { // non-overlapping
                ans.push_back(intervals[i]);
            } else { // overlapping -> store the merged one to i+1
                intervals[i+1][0] = min(intervals[i][0], intervals[i+1][0]);
                intervals[i+1][1] = max(intervals[i][1], intervals[i+1][1]);
            }
        }
        ans.push_back(intervals[n-1]);
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