class Solution {
private:
    vector<vector<bool>> visited;
    int h, w;
    bool ans = false;

public:
    bool exist(vector<vector<char>>& board, string word) {
        h = board.size();
        w = board[0].size();
        for (int i = 0; i < h; i ++) {
            vector<bool> tmp(w, false);
            visited.push_back(tmp);
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                backtracking(board, i, j, 0, word);
                if (ans) {
                    return ans;
                }
            }
        }
        return ans;
    }

private:
    void backtracking(const vector<vector<char>>& board, int i, int j, int word_ind, string& word) {
        if (board[i][j] != word[word_ind] || visited[i][j] || ans) { // not match or have found ans
            return;
        }
        visited[i][j] = true;
        word_ind++;
        if (word_ind == word.size()) { // finish matching
            ans = true;
            return;
        }
        if (i - 1 >= 0) { // go up
            backtracking(board, i - 1, j, word_ind, word);
        }
        if (i + 1 < h) { // go down
            backtracking(board, i + 1, j, word_ind, word);
        }
        if (j - 1 >= 0) { // go left
            backtracking(board, i, j - 1, word_ind, word);
        }
        if (j + 1 < w) { // go right
            backtracking(board, i, j + 1, word_ind, word);
        }
        visited[i][j] = false;
    }

};
/*
we need to enumerate all possibilities and use backtracking
because the same letter cell may not be used more than once -> marked it
for a node, it can go to top down left right 4 directions
if there is no possible choices, go back the last step
*/