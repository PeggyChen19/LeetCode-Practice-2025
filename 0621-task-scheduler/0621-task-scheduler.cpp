class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> type_count(26, 0);
        int max_freq = 0, max_freq_count = 0;
        for (char& task : tasks) {
            int ind = task - 'A';
            type_count[ind]++;
            if (type_count[ind] > max_freq) {
                max_freq_count = 1;
                max_freq = type_count[ind];
            } else if (type_count[ind] == max_freq) {
                max_freq_count++;
            }
        }
        return max((int)tasks.size(), ((n + 1) * (max_freq - 1) + max_freq_count));
    }
};
/*
A A A B B, n = 2
A B _ A B _ A -> 7
Greedy
max(tasks.size, (n + 1) * (max_freq - 1)    +   max_freq_count)
                 ^idle     ^except the last time     ^add the last time -> no idle
*/