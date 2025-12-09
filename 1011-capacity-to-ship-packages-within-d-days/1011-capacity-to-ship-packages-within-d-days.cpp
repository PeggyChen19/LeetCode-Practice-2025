class Solution {
public:
    int calDay(vector<int>& weights, int capacity) {
        int curWeight = 0;
        int day = 1;
        for (int i = 0; i < weights.size(); i++) {
            if (curWeight + weights[i] > capacity) {
                day++;
                curWeight = weights[i];
            } else {
                curWeight += weights[i];
            }
        }
        return day;
    }

    int shipWithinDays(vector<int>& weights, int k) {
        int sum = 0;
        int maxWeights = INT_MIN;
        for (int& w : weights) {
            sum += w;
            maxWeights = max(maxWeights, w);
        }

        int left = maxWeights;
        int right = sum;
        while (right >= left) {
            int mid = left + (right - left) / 2;
            if (calDay(weights, mid) <= k) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
