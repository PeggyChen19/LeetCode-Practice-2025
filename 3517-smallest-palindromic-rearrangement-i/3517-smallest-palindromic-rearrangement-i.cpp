class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> count(26, 0);
        vector<int> ind(26, -1);
        int center = -1;
        string front = "";
        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
            ind[s[i] - 'a'] = i;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 == 1) { // odd -> use one as center
                center = i;
            }
            for (int j = 0; j < count[i] / 2; j++) { // add half to ans
                front += s[ind[i]];
            }
        }
        string back = front;
        reverse(back.begin(), back.end());
        if (center != -1) { // have odd center
            front += s[ind[center]];
        }
        return front + back;
    }
};