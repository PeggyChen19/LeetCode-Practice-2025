class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend());
        for (int i = citations.size() - 1; i >= 0; i--) {
            if (i + 1 <= citations[i]) return i + 1;
        }
        return 0;
    }
};
/*
3 0 6 1 5
Sort:  6 5 3 1 0
Index: 1 2 3 4 5 
Find the largest index where index <= citation 
Time complexity: O(nlogn)
Space complexity: O(1)
*/