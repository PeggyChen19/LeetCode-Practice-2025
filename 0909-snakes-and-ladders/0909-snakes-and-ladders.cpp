class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> visited(n * n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int cell = q.front();
                q.pop();
                if (cell == n * n - 1) return steps;

                for (int dice = 1; dice <= 6; dice++) {
                    int next = cell + dice;
                    if (next >= n * n) continue;

                    int real = getBoardValue(board, next, n);
                    if (!visited[real]) {
                        visited[real] = true;
                        q.push(real);
                    }
                }
            }
            steps++;
        }

        return -1;
    }

private:
    int getBoardValue(const vector<vector<int>>& board, int idx, int n) {
        int r = n - 1 - (idx / n);
        int c = (idx / n) % 2 == 0 ? idx % n : n - 1 - (idx % n);
        return board[r][c] == -1 ? idx : board[r][c] - 1;
    }
};
