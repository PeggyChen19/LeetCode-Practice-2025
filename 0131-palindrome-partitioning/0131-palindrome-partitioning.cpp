class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<int>> palindrome(s.size(), vector<int>(s.size(), -1)); // -1:unknown, 0:false, 1:true
        vector<string> curPartition;
        vector<vector<string>> result;
        backtracking(0, s, curPartition, result, palindrome);
        return result;
    }
private:
    void backtracking(int start, string& s, vector<string>& curPartition, vector<vector<string>>& result, vector<vector<int>>& palindrome) {
        if (start == s.size()) {
            result.push_back(curPartition);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(start, i, s, palindrome)) {
                curPartition.push_back(s.substr(start, i - start + 1));
                backtracking(i + 1, s, curPartition, result, palindrome);
                curPartition.pop_back();
            }
        }
    }
    bool isPalindrome(int start, int end, string& s, vector<vector<int>>& palindrome) {
        if (palindrome[start][end] == 1) return true;
        if (palindrome[start][end] == 0) return false;
        int left = (start + end) / 2;
        int right = (start + end) / 2 + (start + end) % 2;
        while (start <= left && right <= end) {
            if (s[left] != s[right]) {
                palindrome[start][end] = 0;
                return false;
            }
            left--;
            right++;
        }
        palindrome[start][end] = 1;
        return true;
    }
};
/*
Split s into several substrings which are all palindrome
Palindrome -> 從中心向外擴展 -> not work
-> 因為我們是要列出所有的解，所以要用 backtracking，切割點就是選擇，切下去之後再去看是不是回文就好
-> 需要反覆判斷區間是不是回文 -> DP table to memorize
*/