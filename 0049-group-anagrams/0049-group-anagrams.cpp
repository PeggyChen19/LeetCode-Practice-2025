class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, int> anagrams;
        for (string str : strs) {
            string sorted = str;
            sort(sorted.begin(), sorted.end());
            if (!anagrams.count(sorted)) { // new anagram
                anagrams.insert({sorted, anagrams.size()});
                result.push_back({str});
            } else {
                result[anagrams[sorted]].push_back(str);
            }
        }
        return result;
    }
};
/*

init result vector<vector<string>> 
create unordered_map<string, int> to map unique sorted string & result index
sort the string
    (use built in funciton -> time: nlogn, space: 1)
    (OR count sort -> time: n, space: n)
    if it's unique sorted string
        insert into unordered_map, and insert into corresponding result
    if it's exisiting sorted string
        find the index from unorderd_map and push_back to result
*/