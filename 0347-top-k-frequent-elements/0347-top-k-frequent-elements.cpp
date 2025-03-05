class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> countMap; // num:count
        vector<vector<int>> countVec(nums.size() + 1);
        vector<int> ans;
        for (int num : nums) {
            countMap[num]++;
        }
        for (auto [num, count] : countMap) {
            countVec[count].push_back(num);
        }
        for (int i = countVec.size()-1; i >= 0; i--) {
            for (int j: countVec[i]) {
                ans.push_back(j);
                if (ans.size() == k) {
                    return ans;
                }
            }
        }
        return ans;
    }
};
