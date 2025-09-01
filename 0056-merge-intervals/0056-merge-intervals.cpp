class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        vector<int> current = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (current[1] >= intervals[i][0]) { // overlap
                current = {min(current[0], intervals[i][0]), max(current[1], intervals[i][1])};
            } else {
                result.push_back(current);
                current = intervals[i];
            }
        }
        result.push_back(current);
        return result;
    }
};
/*
sort the intervals (by start)
check the overlap (interval[i][1] >= interval[i + 1][0]) -> merge
current interval = the first interval
for each interval
    overlap -> merge
    not overlap
        push current into answer
        change current to the new not overlap interval
*/