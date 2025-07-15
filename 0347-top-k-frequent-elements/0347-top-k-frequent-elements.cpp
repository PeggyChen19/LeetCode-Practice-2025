class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> numToFreq; // num: freq
        vector<vector<int>> freqToNum(n + 1); // freq: nums
        for (auto& num : nums) {
            numToFreq[num]++;
        }
        for (auto& [num, freq] : numToFreq) {
            freqToNum[freq].push_back(num);
        }
        vector<int> result;
        for (int i = n; i >= 0; i--) {
            for (int j = 0; j < freqToNum[i].size(); j++) {
                result.push_back(freqToNum[i][j]);
                if (result.size() == k) return result;
            }
        }
        return result;
    }
};
/*
Target: Time complexity O(n)
unordered_map<int, int> to record num: frequency
vector<vector<int>> to record frequency: num vector, size(nums.size())
1. go through nums to update unordered_map
2. go through map to update vector
3. pick the top k frenquency
Time: O(n), Space: O(n)
*/