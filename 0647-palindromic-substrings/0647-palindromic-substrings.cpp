class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            int odd = expandFromCenter(s, i, i);
            int even = expandFromCenter(s, i, i+1);
            ans += odd + even;
        }
        return ans;
    }
private:
    int expandFromCenter(string s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
            count++;
        }
        return count;
    }

};
/*
for all char in s
    use char as odd substring center
    expand and record count
    use char & char+1 as even substring center
    expand and record count
Time: O(n^2)
Space: O(1)
*/