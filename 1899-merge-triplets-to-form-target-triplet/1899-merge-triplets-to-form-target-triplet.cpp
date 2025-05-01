class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool a = false, b = false, c = false;
        for (vector<int> t : triplets) {
            if (t[0] <= target[0] && t[1] <= target[1] && t[2] <= target[2]) {
                if (t[0] == target[0]) a = true;
                if (t[1] == target[1]) b = true;
                if (t[2] == target[2]) c = true;
            }
        }
        return a && b && c;
    }
};
/*
1 2 3
5 1 2
4 7 1
target: 5 7 3 -> true
target: 4 7 2 -> false

for each target element, we need to find out where it is in triplets
for all filtered out triplets, the max value of each position must be target

bool a, b, c = false; //target
for (t : triplets)
    if (t[0] <= a && t[1] <= b && t[2] <= c) {
        if (t[0] == a) a = true;
        if (t[1] == b) b = true;
        if (t[2] == c) c = true;
    }
return a && b && c

*/