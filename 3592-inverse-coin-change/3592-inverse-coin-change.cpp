class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();
        vector<int> curWays(n, 0);
        vector<int> amounts; // return goal
        int i = 0; // the unmatched index
        while (i < n) {
            while (i < n && curWays[i] == numWays[i]) {
                i++;
            }
            if (i == n) return amounts;
            if (curWays[i] + 1 != numWays[i]) return {};
            int newAmount = i + 1;
            amounts.push_back(newAmount);
            for (int start = i ; start < n; start++) {
                if (start - newAmount < 0) {
                    curWays[start] += 1;
                } else {
                    curWays[start] += curWays[start - newAmount];
                }
            }
            i++;
        }
        return amounts;
    }
};