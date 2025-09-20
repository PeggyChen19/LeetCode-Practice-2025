class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int result = 0;
        unordered_set<char> broken;
        for (char ch : brokenLetters) {
            broken.insert(ch);
        }
        istringstream iss(text);
        string word;
        while (getline(iss, word, ' ')) {
            bool valid = true;
            for (char ch : word) {
                if (broken.count(ch)) {
                    valid = false;
                    break;
                }
            }
            result += valid ? 1 : 0;
        }
        return result;
    }
};
/*
use unordered_set / vector to record broken letters
go through each word (use getline) and check
*/