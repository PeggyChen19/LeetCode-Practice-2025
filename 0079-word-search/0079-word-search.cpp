class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int h = board.size(), w = board[0].size();
        vector<vector<bool>> visited(h, vector<bool>(w, false));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (backtracking(board, visited, i, j, 0, word)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool backtracking(const vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, int word_ind, string& word) {
        if (board[i][j] != word[word_ind] || visited[i][j]) { // not match or have visited
            return false;
        }        
        if (word_ind == word.size() - 1) { // finish matching
            return true;
        }
        visited[i][j] = true;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int k = 0; k < directions.size(); k++) {
            int x = i + directions[k].first;
            int y = j + directions[k].second;
            if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size()) {
                if (backtracking(board, visited, x, y, word_ind + 1, word)) {
                    return true;
                }
            }
        }
        visited[i][j] = false;
        return false;
    }
};
/*
we need to enumerate all possibilities and use backtracking
because the same letter cell may not be used more than once -> marked it
for a node, it can go to top down left right 4 directions
if there is no possible choices, go back the last step
*/