class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int, int> count = {{0, 0}, {1, 0}, {2, 0}};
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
        }
        int i = 0;
        for (int color = 0; color < 3; color++) {
            for (int j = 0; j < count[color]; j++) {
                nums[i] = color;
                i++;
            }
        }
    }
};