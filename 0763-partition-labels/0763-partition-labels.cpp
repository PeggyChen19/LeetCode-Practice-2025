class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> result;
        unordered_map<char, int> last_position;
        for (int i = 0; i < s.size(); i++) {
            last_position[s[i]] = i;
        }
        int start = 0;
        int max_position = 0;
        for (int i = 0; i < s.size(); i++) {
            max_position = max(max_position, last_position[s[i]]);
            if (max_position == i) { // partition now
                result.push_back(max_position - start + 1);
                start = i + 1;
            }
        }
        return result;
    }
};
/*
"ababcc" -> "abab", "cc"
target: max num of parts
limit: every char can only exist in 1 part

record the last position of each char (unordered_map)
how about the first time? we go throught the string from the start
start = 0
max_position = 0
for i = 0; i < s.size; i++
    max_position = max(max_position, map[s[i]])
    if (max_position == i) // partition
        result.push(max_position - start + 1)
        start = i+1
*/