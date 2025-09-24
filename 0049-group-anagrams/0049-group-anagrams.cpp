class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, int> anagrams;
        for (string str : strs) {
            vector<int> counts(26, 0);
            for (char ch : str) {
                counts[ch - 'a']++;
            }
            string key = "";
            for (int count : counts) {
                key += to_string(count) + "#";
            }
            if (!anagrams.count(key)) { // new anagram
                anagrams.insert({key, anagrams.size()});
                result.push_back({str});
            } else {
                result[anagrams[key]].push_back(str);
            }
        }
        return result;
    }
};
/*
init result vector<vector<string>> 
create unordered_map<string, int> to map unique sorted string & result index
sort the string
		(freqnecy count -> time: n, space: 1) -> better
    (use built in funciton -> time: nlogn, space: 1)
    if it's unique sorted string
        insert into unordered_map, and insert into corresponding result
    if it's exisiting sorted string
        find the index from unorderd_map and push_back to result
*/