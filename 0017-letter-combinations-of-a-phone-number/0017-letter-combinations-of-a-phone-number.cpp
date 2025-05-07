class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.size() == 0) {
            return result;
        }
        string path = "";
        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        backtracking(digits, 0, path, mapping, result);
        return result;
    }

private:
    void backtracking(string& digits, int ind, string& path, vector<string>& mapping, vector<string>& result) {
        if (ind == digits.size()) {
            result.push_back(path);
            return;
        }
        int digit = digits[ind] - '0';
        for (char ch : mapping[digit]) {
            path.push_back(ch);
            backtracking(digits, ind + 1, path, mapping, result);
            path.pop_back();
        }
    }
};
/*
all combinations -> backtracking
use vector<string> to record the mapping
void backtracking(digits, ind, string& str)
    if ind = digits.size
        result.push_back(str)
        return
    for (char : mapping[digits[ind]])
        str.push_back(char)
        backtracking(digits, ind+1, str)
        str.pop_back()
*/