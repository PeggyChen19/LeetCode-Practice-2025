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
    TrieNode* getRoot() {
        return root;
    }
    Trie (vector<string>& words) {
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
private:
    TrieNode* root;
};

class Solution {
private:
    unordered_set<string> ans_set;
    const vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    void findWordFromTrie(vector<vector<char>>& board, int x, int y, string str, TrieNode* cur) {
        if (cur->is_end) {
            ans_set.insert(str);
        }
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || !board[x][y]) {
            return;
        }
        char ch = board[x][y];
        if (cur->children[ch - 'a'] != NULL) { // have this char in board
            cur = cur->children[ch - 'a'];
            board[x][y] = '\0';
            for (auto [dx, dy] : directions) {
                findWordFromTrie(board, (x + dx), (y + dy), (str + ch), cur);
            }
            board[x][y] = ch;
        }
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie = new Trie(words);
        TrieNode* root = trie->getRoot();
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                findWordFromTrie(board, i, j, "", root);
            }
        }
        vector<string> ans;
        for (auto str : ans_set) {
            ans.push_back(str);
        }
        return ans;
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