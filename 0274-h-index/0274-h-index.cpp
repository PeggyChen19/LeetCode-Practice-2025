class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> count(n + 1, 0);
        for (int& citation : citations) {
            citation = min(citation, n);
            count[citation]++;
        }
        int total = 0;
        for (int i = n; i >= 0; i--) {
            total += count[i];
            if (total >= i) {
                return i;
            }
        }
        return 0;
    }
};
/*
3 0 6 1 5
Counting Sort
Create vector(n+1) to record the citations count
From n to 0, accumulate the total. return the first total >= index
*/