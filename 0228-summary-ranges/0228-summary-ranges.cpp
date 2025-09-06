class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.empty()) return result;
        int start = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == nums.size() - 1 || nums[i] + 1 != nums[i + 1]) { // end OR not continuous -> push current interval
                if (nums[start] == nums[i]) {
                    result.push_back(to_string(nums[start]));
                } else {
                    result.push_back(to_string(nums[start]) + "->" + to_string(nums[i]));
                }
                start = i + 1;
            }
        }
        return result;
    }
};
/*
1. record the start of the unvisited array
2. keep going until there is not continuous / reaching the end
3. push the interval into the result vector "start->end" / "start"
4. repeat 1 to 3
*/