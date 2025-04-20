class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> map; // our need for this char
        int unmatched = t.size();
        int left = 0, right = 0, head = 0, minL = s.size()+1;
        for (char c : t) {
            map[c]++;
        }
        while (right < s.size()) {
            if (map[s[right]] > 0) { // s[right] matches unmatched element in t
                unmatched--;
            }
            map[s[right]]--; // our need reduce because we add s[right]
            while (unmatched == 0) { // satisfy the condition -> keep finding the min
                int cur_len = right - left + 1;
                if (cur_len < minL) { // update min
                    head = left;
                    minL = cur_len;
                }
                map[s[left]]++; // our need increase because we remove s[left]
                if (map[s[left]] > 0) { // there is more need than we have
                    unmatched++;
                }
                left++;
            }
            right++;
        }
        return (minL == s.size()+1) ? "" : s.substr(head, minL);
    }
};
/*
Sliding window:
create a var to record the min
set left and right at the first element
while right didn't reach the end
    put right into window
    while satisfy the conditin 
        update result(min)
        shrink left
    expand right

How to check it is valid or not
unordered_map -> char_t : counts
total -> the number of unmatch
*/