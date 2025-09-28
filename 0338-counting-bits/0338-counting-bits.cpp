class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1, 0);
        result[0] = 0;
        if (n == 0) return result;
        result[1] = 1;
        for (int i = 2; i <= n; i++) {
            result[i] = result[i >> 1] + (i % 2);
        }
        return result;
    }
};
/*
  0
  1
 10
 11
100
101
110

i >> 1 which means divide by 2 -> must exist before i (because it's smaller)
if lowest bit == 1
    result[i] = result[i >> 1] + 1
else
    result[i] = result[i >> 1]
*/