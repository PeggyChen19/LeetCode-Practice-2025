class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> results;
        bool inserted = false;
        for (vector<int> interval : intervals) {
            if (inserted || interval[1] < newInterval[0]) {
                results.push_back(interval);
            }
            else if (newInterval[1] < interval[0]) {
                results.push_back(newInterval);
                results.push_back(interval);
                inserted = true;
            } else {
                newInterval[0] = min(newInterval[0], interval[0]);
                newInterval[1] = max(newInterval[1], interval[1]);
            }
        }
        if (!inserted) {
            results.push_back(newInterval);
        }
        return results;
    }
};
/*
intervals are non-overlapping -> sort both by start and end
go through all i in intervals
    if i.end < new.start // non-overlap and i before new
        insert i
    else if new.end < i.start // non-overlap and new before i
        insert new
        insert i
    else // overlap -> update new
        combine i into new
*/