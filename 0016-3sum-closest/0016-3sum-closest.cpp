class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int closest = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i - 1] == nums[i]) continue; // avoid duplication
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (abs(target - sum) < abs(target - closest)) { // find a closer ans
                    closest = sum;
                }
                if (sum == target) return target;
                else if (sum > target) {
                    do right--; while (left < right && nums[right] == nums[right + 1]);
                } else {
                    do left++; while (left < right && nums[left - 1] == nums[left]);
                }
            }
        }
        return closest;
    }
};
/*
maintain a global int minDiff
do something like find 3 int that sums up to exactly target -> try to be as close to the ans as possible

int minDiff = INT_MAX
sort(nums)
for (int i = 0; i < size; i++)
    fix i as the first element
    create two pointers: left = i + 1, right = size - 1
        move left & right to try get closer to the target, update minDiff if found a closer one
return target - minDiff
*/