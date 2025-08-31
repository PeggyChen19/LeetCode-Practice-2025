class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        minHeap.push({nums1[0] + nums2[0], 0, 0});
        while (k > 0 && !minHeap.empty()) {
            int i = minHeap.top()[1];
            int j = minHeap.top()[2];
            minHeap.pop();
            result.push_back({nums1[i], nums2[j]});
            k--;
            if (j + 1 < nums2.size()) minHeap.push({nums1[i] + nums2[j + 1], i, j + 1});
            if (j == 0 && i + 1 < nums1.size()) minHeap.push({nums1[i + 1] + nums2[j], i + 1, j});
        }
        return result;
    }
};
/*
1D -> each step expose one new candidate -> two pointers
2D (pair) -> each step expose multiple new candidates -> find min from all candidates -> min heap
*/