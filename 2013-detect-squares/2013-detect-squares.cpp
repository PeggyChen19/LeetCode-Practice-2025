class DetectSquares {
private:
    unordered_map<string, int> counts; // point, count
    unordered_map<int, vector<int>> x_point; // x, vector y
public:
    DetectSquares() {}
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        counts[convertFormat(point)]++;
        x_point[x].push_back(y);
    }
    
    int count(vector<int> point) {
        int result = 0;
        int x = point[0];
        int y = point[1];
        for (auto& y_candidate : x_point[x]) {
            int len = y_candidate - y;
            if (len == 0) continue;
            result += (counts[convertFormat({x + len, y})] * counts[convertFormat({x + len, y_candidate})]);
            result += (counts[convertFormat({x - len, y})] * counts[convertFormat({x - len, y_candidate})]);
        }
        return result;
    }
private:
    string convertFormat(vector<int> point) {
        return to_string(point[0]) + "#" + to_string(point[1]);
    }
};
/**
Add: Duplicate points are allowed and should be treated as different points
Count: Axis-aligned square with positive area

Count:
Given point (x, y)
find all points with the same x
    find the other two points to build a square

Which data structure to store points?
Find (x, y), (x, _) quickly
Store duplicated points

unordered_map<pair<int, int>, int> // (x, y), count
unordered_map<int, vector<int>> // x, y

* Your DetectSquares object will be instantiated and called as such:
* DetectSquares* obj = new DetectSquares();
* obj->add(point);
* int param_2 = obj->count(point);
*/