class TrieNode {
public:
    bool isEnd;
    TrieNode* child[26];
    TrieNode(): isEnd(false) {
        for(int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int ind = c - 'a';
            if (!node->child[ind]) {
                node->child[ind] = new TrieNode();    
            }
            node = node->child[ind];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* end_node = find(word);
        return (end_node && end_node->isEnd);
    }
    
    bool startsWith(string prefix) {
        return (find(prefix));
    }

private:
    TrieNode* find(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int ind = c - 'a';
            if (node->child[ind]) {
                node = node->child[ind];
            } else {
                return nullptr;
            }
        }
        return node;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */