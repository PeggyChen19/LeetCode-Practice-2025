class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int nonOverlap = 1; // points[0];
        for (int i = 1; i < points.size(); i++) {
            if (points[i - 1][1] >= points[i][0]) { // leave the overlapped part at i (compare to i + 1 later)
                points[i][0] = max(points[i - 1][0], points[i][0]);
                points[i][1] = min(points[i - 1][1], points[i][1]);
            } else {
                nonOverlap++;
            }
        }
        return nonOverlap;
    }
};
/*
Combine the partly overlapped intervals, return the number of non-overlapping intervals
How?
Sort the points based on start points
for all points
    if (p[i - 1].end > p[i].start): overlap -> combine
return the non-overlapping counts

Time Complexity: O(nlogn)
*/