class Solution {
public:
    int findClosest(int x, int y, int z) {
        int dis_x = abs(x - z);
        int dis_y = abs(y - z);
        if (dis_x < dis_y) {
            return 1;
        } else if (dis_y < dis_x) {
            return 2;
        } else {
            return 0;
        }
    }
};