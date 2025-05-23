class Solution {
private:
    int quickSelect(int left, int right, vector<pair<int, vector<int>>>& dist) {
        int pivot = dist[left].first, l = left + 1, r = right;
        while (l <= r) {
            if (dist[l].first > pivot && dist[r].first < pivot) {
                swap(dist[l], dist[r]);
                l++;
                r--;
            }
            if (dist[l].first <= pivot) l++;
            if (dist[r].first >= pivot) r--;
        }
        swap(dist[left], dist[r]);
        return r;
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, vector<int>>> dist; // distance, point vector
        for (auto& point : points) {
            int distance = point[0] * point[0] + point[1] * point[1];
            dist.push_back({distance, point});
        }
        int left = 0, right = points.size() - 1;
        while (true) {
            int pivotInd = quickSelect(left, right, dist);
            if (pivotInd == k) {
                break;
            } else if (pivotInd > k) { // go left
                right = pivotInd - 1;
            } else { // go right
                left = pivotInd + 1;
            }
        }
        vector<vector<int>> results;
        for (int i = 0; i < k; i++) {
            results.push_back(dist[i].second);
        }
        return results;
    }
};
/*
Quick Select
int quickSelect(left, right) // small to big
    pivot = dist[left], l = left+1, r = right
    while (l <= r)
        if (dist[l] > pivot && dist[r] < pivot)
            swap(dist[l], dist[r])
            l++
            r--
        if (dist[l] <= pivot)
            l++
        if (dist[r] >= pivot)
            r--
    swap(dist[left], dist[r]) // [r l] at this time (r <= pivot -> swap to left side)
    return r;

main func
    pivotInd = quickSelect(start, end)
    adjust range based on pivotInd
*/