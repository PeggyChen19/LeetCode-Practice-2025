class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> sMap;
        if (s.size() != t.size()) {
            return false;
        }
        for (int i = 0; i < s.size(); i++) {
            sMap[s[i]]++;
        }
        for (int i = 0; i < t.size(); i++) {
            sMap[t[i]]--;
        }
        for (auto it = sMap.begin(); it != sMap.end(); it++) {
            if (it->second != 0) {
                return false;
            }
        }
        return true;
    }
};

/*
Solution 1:
1. sort both string and store in a vector
2. compare from the first to the last
T: O(nlogn)
S: O(n)

Solution 2: -> better
1. for the first string, store in an unordred set
2. go through the second string, and find the character in the set. if find it, then remove it, if not, return false
3. check if the set is empty
T: O(n)
S: O(1)

Solution 3: -> best
Just simply use array to record it
T: O(n)
S: O(1)
*/