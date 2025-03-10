class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int maxFreq = 0, slow = 0, ans = 0;
        for (int fast = 0; fast < s.size(); fast++) {
            freq[s[fast] - 'A']++;
            maxFreq = max(maxFreq, freq[s[fast] - 'A']);
            while (fast - slow + 1 - maxFreq > k) {
                freq[s[slow] - 'A']--;
                slow++;
            }
            ans = max(ans, fast - slow + 1);
        }
        return ans;
    }
};

/*
要求的是「連續區間」，所以會想到 sliding window，問題是該怎麼收縮 window
關鍵是這個 window 內需要 replace 次數有沒有超過上限 -> replace 次數 = (window length - 最主要的字母次數)

vector<int> freq(26, 0)
maxFreq = 0
ans = 0
fast pointer go through the string
    update freq
    update maxFreq
    while windowLen - maxFreq > k
        shrink window (slow)
    update ans
*/