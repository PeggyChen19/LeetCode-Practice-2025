class DicNode {
public:
    DicNode* child[26];
    bool isEnd;
    DicNode(): isEnd(false) {
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }
};

class WordDictionary {
private:
    DicNode* root;
public:
    WordDictionary() {
        root = new DicNode();
    }
    
    void addWord(string word) {
        DicNode* node = root;
        for (char c : word) {
            int ind = c - 'a';
            if(!node->child[ind]) {
                node->child[ind] = new DicNode();
            }
            node = node->child[ind];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        DicNode* node = root;
        return searchHelper(node, 0, word);
    }

private:
    bool searchHelper(DicNode* node, int word_ind, string word) {
        if (!node) {
            return false;
        }
        if (word_ind == word.size()) {
            return node->isEnd;
        }
        if (word[word_ind] == '.') {
            for (int i = 0; i < 26; i++) {
                if (searchHelper(node->child[i], word_ind + 1, word)) {
                    return true;
                }
            }
        } else { // normal case
            int ind = word[word_ind] - 'a';
            if (searchHelper(node->child[ind], word_ind + 1, word)) {
                return true;
            }
        }
        return false;
    }
};
/*
similar as the trie tree. for dot ".", we need to go to all possible char
*/

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */