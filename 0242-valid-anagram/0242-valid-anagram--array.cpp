class Solution {
public:
    bool isAnagram(string s, string t) {
        int frequent[26] = {0};
        if (s.size() != t.size()) {
            return false;
        }
        for (int i = 0; i < s.size(); i++) {
            frequent[s[i]-'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            frequent[t[i]-'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (frequent[i] != 0) {
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
S: O(n)

Solution 3: -> best
Just simply use vector to record it

T: O(n)
S: O(n)


*/