class TrieNode {
public:
    bool is_end;
    vector<TrieNode*> children;
    TrieNode() {
        is_end = false;
        children = vector<TrieNode*>(26, NULL);
    }
};

class Trie {
public:
    TrieNode* root;
    Trie(vector<string>& words) {
        root = new TrieNode();
        for (string word : words) {
            addWord(word);
        }
    }
    void addWord(const string& word) {
        TrieNode* cur = root;
        for (char c : word) {
            int ind = c - 'a';
            if (cur->children[ind] == NULL) {
                cur->children[ind] = new TrieNode();
            }
            cur = cur->children[ind];
        }
        cur->is_end = true;
    }
};

class Solution {
private:
    unordered_set<string> results;
    const vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    void dfs(vector<vector<char>>& board, int x, int y, string& path, TrieNode* cur) {
        char ch = board[x][y];
        if (cur->children[ch - 'a'] != NULL) { // have this char in board
            cur = cur->children[ch - 'a'];
            path.push_back(ch);
            if (cur->is_end) {
                results.insert(path);
                cur->is_end = false; // avoid duplicate operations
            }
            board[x][y] = '\0';
            for (auto [dx, dy] : directions) {
                int i = x + dx;
                int j = y + dy;
                if (i >= 0 && i < board.size() && j >= 0 && j < board[0].size() && board[i][j]) {
                    dfs(board, i, j, path, cur);
                }
            }
            board[x][y] = ch;
            path.pop_back();
        }
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie = new Trie(words);
        string path = "";
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, path, trie->root);
            }
        }
        return vector<string>(results.begin(), results.end());
    }
};
/*
Brute force solution:
For each word
    Use DFS to check if the word exists or not
DFS:    
Clear the char when visited
Go to all possible directions
Set the char back to the original

Improvement:
Use all words to build a Trie
-> We can store words together with common prefix
-> Pruning: if the current string from the board isn't in Trie, stop it
*/