class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int steps = 0, n = board.size();
        int dst = n * n - 1;
        vector<bool> visited(dst, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int cell = q.front();
                q.pop();
                if (cell == dst) return steps;
                for (int dice = 1; dice <= 6; dice++) {
                    int next = cell + dice;
                    if (next > dst || visited[next]) continue;
                    visited[next] = true;
                    int val = findBoardVal(board, next, n);
                    if (val == -1) q.push(next); // no ladder or snake
                    else q.push(val); // ladder -> go to dst
                }
            }
            steps++;
        }
        return -1;
    }
private:
    int findBoardVal(const vector<vector<int>>& board, const int& index, const int& n) {
        int divide = index / n;
        int mod = index % n;
        int x = (n - 1) - divide;
        int y = (divide % 2) ? (n - 1) - mod : mod;
        return board[x][y] == -1 ? -1 : board[x][y] - 1;
    }
};
/*
Limitation:
Cannot take the ladder more than once in the same step

Greedy (use BFS)
Use a queue to record all reachable cells of each round
For each cell, expand the possible next cells (i+1 ~ i+6 + ladder's dst)
*/