class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<tuple<double, int, int>> maxHeap; // {diff, pass, total}
        for (int i = 0; i < n; i++) {
            int pass = classes[i][0], total = classes[i][1];
            double diff = double(pass + 1) / (total + 1) - (double(pass) / total);
            maxHeap.push({diff, pass, total});
        }
        for (int i = 0; i < extraStudents; i++) {
            auto [diff, pass, total] = maxHeap.top();
            maxHeap.pop();
            pass++;
            total++;
            diff = double(pass + 1) / (total + 1) - (double(pass) / total);
            maxHeap.push({diff, pass, total});
        }
        double totalRatio = 0.0;
        for (int i = 0; i < n; i++) {
            auto [diff, pass, total] = maxHeap.top();
            maxHeap.pop();
            totalRatio += (double)pass / total;
        }
        return totalRatio / n;
    }
};
/*
avg pass ration = ((pass1 / total1) + (pass2 / total2) + .... (passn / totaln)) / n
max( (pass + 1) / (total + 1) - pass / total ) -> priority_queue -> ensure us to always get the max difference of current state

Time Complexity: O(n + max(n, k) * logn)
Space Complexity: O(n)
*/