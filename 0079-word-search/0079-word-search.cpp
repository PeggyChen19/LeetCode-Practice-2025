class Solution {
private:
    const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    bool exist(vector<vector<char>>& board, string word) {
        int h = board.size(), w = board[0].size();
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (dfs(board, i, j, 0, word)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, int i, int j, int word_ind, const string& word) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[word_ind]) { 
            return false; // out of range || not match || have visited
        }
        if (word_ind == word.size() - 1) { // finish matching
            return true;
        }
        char tmp = board[i][j];
        board[i][j] = '#';
        for (int k = 0; k < directions.size(); k++) {
            int x = i + directions[k].first;
            int y = j + directions[k].second;
            if (dfs(board, x, y, word_ind + 1, word)) {
                return true;
            }
        }
        board[i][j] = tmp;
        return false;
    }
};
/*
we need to enumerate all possibilities and use backtracking
because the same letter cell may not be used more than once -> marked it
for a node, it can go to top down left right 4 directions
if there is no possible choices, go back the last step
*/