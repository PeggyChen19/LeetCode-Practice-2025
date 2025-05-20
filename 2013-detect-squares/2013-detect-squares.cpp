class DetectSquares {
private:
    unordered_map<int, unordered_map<int, int>> points; // (x, (y, count)
public:
    DetectSquares() {}
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        points[x][y]++;
    }

    int count(vector<int> point) {
        int result = 0;
        int x = point[0];
        int y = point[1];
        for (auto& [y2, y2Count] : points[x]) {
            int len = y2 - y;
            if (len == 0) continue;
            result += y2Count * points[x + len][y] * points[x + len][y2];
            result += y2Count * points[x - len][y] * points[x - len][y2];
        }
        return result;
    }
};
/**
Add: Duplicate points are allowed and should be treated as different points
Count: Axis-aligned square with positive area

Count:
Given point (x, y)
find all points with the same x
    find the other two points to build a square
    consider counts

Which data structure to store points?
Find (x, y), (x, _) quickly
Store duplicated points
-> unordered_map<int, unordered_map<int, int>> -> (x, (y, count)

* Your DetectSquares object will be instantiated and called as such:
* DetectSquares* obj = new DetectSquares();
* obj->add(point);
* int param_2 = obj->count(point);
*/