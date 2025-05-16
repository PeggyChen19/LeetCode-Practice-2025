class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<int>> mem(n, vector<int>(n, -1)); // -1:unknown, 0:false, 1:true
        vector<string> partitions;
        vector<vector<string>> result;
        backtracking(0, s, partition, result, mem);
        return result;
    }
private:
    void backtracking(int start, const string& s, vector<string>& partitions, 
                      vector<vector<string>>& result, vector<vector<int>>& mem) {
        if (start == s.size()) {
            result.push_back(curPartition);
            return;
        }
        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(start, end, s, palindrome)) {
                partitions.push_back(s.substr(start, end - start + 1));
                backtracking(end + 1, s, partition, result, palindrome);
                partitions.pop_back();
            }
        }
    }
    bool isPalindrome(int start, int end, string& s, vector<vector<int>>& palindrome) {
        if (palindrome[start][end] == 1) return true;
        if (palindrome[start][end] == 0) return false;
        int left = start, right = end;
        while (left < right) {
            if (s[left] != s[right]) {
                palindrome[start][end] = 0;
                return false;
            }
            left++;
            right--;
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