class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.size() == 0) {
            return {newInterval};
        }
        vector<vector<int>> ans;
        int i = 0;
        int n = intervals.size();
        while (i < n && intervals[i][1] < newInterval[0]) { // before new
            ans.push_back(intervals[i]);
            i++;
        }
        while (i < n && newInterval[1] >= intervals[i][0]) { // overlapping
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
        ans.push_back(newInterval);
        while (i < n) { // after new
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};

/*
[1, 3], [7, 9]
New: [4, 5] -> [1, 3], [4, 5], [7, 9]
New: [2, 5] -> [1, 5], [7, 9]
New: [2, 10] -> [1, 10]

For intervals before new (i.end < new.start) -> insert to ans directly
For intervals overlap new (new.end >= i.start) -> merge
For intervals after new (new.end < i.start) -> insert to ans directly

*/