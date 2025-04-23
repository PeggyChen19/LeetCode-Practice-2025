class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> map;
        int unmatched = s1.size(), begin = 0, end = 0;
        for (char c : s1) {
            map[c]++;
        }
        while (end < s2.size()) {
            if (map[s2[begin]] == 0) { // not match -> move both begin & end toward next
                begin++;
                end = begin;
            } else {
                while (end < s2.size() && map[s2[end]] > 0) { // matching
                    map[s2[end]]--;
                    unmatched--;
                    end++; // expanding end
                    if (unmatched == 0) {
                        return true;
                    }
                }
                // matched failed -> shrink begin
                map[s2[begin]]++;
                unmatched++;
                begin++;
            }
        }
        return false;
    }
};
/*
s1 = a b c
s2 = d c a b e

substring -> sliding window

unordered_map s(s1) // char:count
umatched = s1.size()
begin = 0, end = 0
while end < s2.end
    if s2[begin] not in s1
        begin++
        end = max(begin, end)
    else
        while end < s2.end && s2[end] in s1
            end++
            return if inclusion
        // matched failed
        begin++
*/