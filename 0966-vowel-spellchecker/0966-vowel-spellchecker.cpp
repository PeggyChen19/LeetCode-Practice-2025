class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> result;
        unordered_set<string> original;
        unordered_map<string, string> lowerCase;
        unordered_map<string, string> deVowel;
        for (string& word : wordlist) {
            original.insert(word);
            string lowerCaseWord = toLowerStr(word);
            if (!lowerCase.count(lowerCaseWord)) {
                lowerCase.insert({lowerCaseWord, word});
            }
            string deVowelWord = deVowelStr(lowerCaseWord);
            if (!deVowel.count(deVowelWord)) {
                deVowel.insert({deVowelWord, word});
            }
        }
        for (string& query : queries) {
            string lowerCaseQuery = toLowerStr(query);
            string deVowelQuery = deVowelStr(lowerCaseQuery);
            if (original.count(query)) result.push_back(query);
            else if (lowerCase.count(lowerCaseQuery)) result.push_back(lowerCase[lowerCaseQuery]);
            else if (deVowel.count(deVowelQuery)) result.push_back(deVowel[deVowelQuery]);
            else result.push_back("");
        }
        return result;
    }
private:
    string toLowerStr(string s) {
        for (int i = 0; i < s.size(); i++) {
            s[i] = tolower(s[i]);
        }
        return s;
    }

    string deVowelStr(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                s[i] = '*';
            }
        }
        return s;
    }
};
/*
if there is case sensitive match
    must return it
else
    return the "first" match via capitalization OR vowel errors

quick find -> hash table
3 kinds of hash table
unordered_set<string> original list
unordered_map<string, string> lower-case list, original list
unordered_map<string, string> lower-case & de-vowel list, original list (change all vowels to *)

store list to the above 3 hash table (note: only store the first same pattern in table 2 & 3)

for each query
    find the query in the 3 hash table in order
*/