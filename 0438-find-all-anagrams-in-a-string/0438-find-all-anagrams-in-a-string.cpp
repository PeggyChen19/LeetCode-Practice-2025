class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> results;
        if (p.size() > s.size()) return results;
        int unmatched = p.size();
        unordered_map<char, int> counts;
        for (char& ch : p) {
            counts[ch]++;
        }
        int start = 0;
        for (int end = 0; end < s.size(); end++) {
            if (counts[s[end]] > 0) { // will add matched char into window
                unmatched--;
            }
            counts[s[end]]--;
            if (end - start + 1 == p.size()) {
                if (unmatched == 0) {
                    results.push_back(start);
                }
                if (counts[s[start]] >= 0) { // will remove matched char from window
                    unmatched++;
                }
                counts[s[start]]++;
                start++;
            }
        }
        return results;
    }
};
/*
Find the p's anagrams in s (the same components with any order)
s = "cbaebabacd", p = "abc" -> [0,6]
Use unordered_map & p.size() to represent p
Sliding window go through s and find anagrams
*/