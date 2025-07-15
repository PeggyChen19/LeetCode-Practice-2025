class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        if (earlyStop(board, m, n, word)) return false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, i, j, word, 0, m, n)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
private:
    const vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; 
    bool dfs(vector<vector<char>>& board, int i, int j, string& word, int ind, int& m, int& n) {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[ind]) return false;
        if (ind == word.size() - 1) return true;
        board[i][j] = '#';
        for (auto& [dx, dy] : directions) {
            int x = i + dx;
            int y = j + dy;
            if (dfs(board, x, y, word, ind + 1, m, n)) return true;
        }
        board[i][j] = word[ind];
        return false;
    }

    bool earlyStop(vector<vector<char>>& board, int m, int n, string& word) {
        vector<int> wordFreq(100, 0);
        vector<int> boardFreq(100, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                boardFreq[board[i][j] - 'A']++;
            }
        }
        for (int i = 0; i < word.size(); i++) {
            char c = word[i] - 'A';
            wordFreq[c]++;
            if (wordFreq[c] > boardFreq[c]) return true;
        }
        if (wordFreq[word[0] - 'A'] > wordFreq[word.back() - 'A']) reverse(word.begin(), word.end());
        return false;
    }
};
/*
Try all possibilities: Backtracking(DFS)
modify the board when visited, convert it back when backtracking

Pruning method:
1. Early return, compare word's char frequency v.s. board's char frequency
2. Start from less frequent char (word.begin() or word.end())
*/