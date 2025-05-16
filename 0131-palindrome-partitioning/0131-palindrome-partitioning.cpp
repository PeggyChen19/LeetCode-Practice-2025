class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<int>> mem(n, vector<int>(n, -1)); // -1:unknown, 0:false, 1:true
        vector<string> partitions;
        vector<vector<string>> result;
        backtracking(0, s, partitions, result, mem);
        return result;
    }
private:
    void backtracking(int start, string& s, vector<string>& partitions, 
                      vector<vector<string>>& result, vector<vector<int>>& mem) {
        if (start == s.size()) {
            result.push_back(partitions);
            return;
        }
        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(start, end, s, mem)) {
                partitions.push_back(s.substr(start, end - start + 1));
                backtracking(end + 1, s, partitions, result, mem);
                partitions.pop_back();
            }
        }
    }
    bool isPalindrome(int start, int end, string& s, vector<vector<int>>& mem) {
        if (start >= end) return true;
        if (mem[start][end] != -1) return mem[start][end];
        mem[start][end] = (s[start] == s[end] && isPalindrome(start + 1, end - 1, s, mem)) ? 1 : 0;
        return mem[start][end];
    }
};
/*
Split s into several substrings which are all palindrome
Palindrome -> 從中心向外擴展 -> not work
-> 因為我們是要列出所有的解，所以要用 backtracking，切割點就是選擇，切下去之後再去看是不是回文就好
-> 需要反覆判斷區間是不是回文 -> DP table to memorize
*/