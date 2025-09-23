class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s = "";
        int unmatchedL = 0;
        int remainedL = n;
        buildString(unmatchedL, remainedL, s, result);
        return result;
    }
private:
    void buildString(int unmatchedL, int remainedL, string s, vector<string>& result) {
        if (unmatchedL == 0 && remainedL == 0) {
            result.push_back(s);
            return;
        }
        if (remainedL > 0) { // push left
            buildString(unmatchedL + 1, remainedL - 1, s + '(', result);
        }
        if (unmatchedL > 0) { // push right
            buildString(unmatchedL - 1, remainedL, s + ')', result);
        }
    }
};
/*
n = 2, must have 2 ( and 2 ), we need to build valid combinations
( -> () -> ()( -> ()()
  -> (( -> (() -> (())

backtracking
for each step, we can choose
1. push left if there are remained left
2. push right if there are unmatched left
terminate condition
remainedL == 0 && unmatchedL == 0
*/