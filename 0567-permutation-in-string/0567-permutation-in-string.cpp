class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		vector<int> freq(26, 0);
		int unmatched = s1.size(), left = 0;
		for (char c : s1) {
			freq[c - 'a']++;
		}
		for (int right = 0; right < s2.size(); right++) {
			if (freq[s2[right] - 'a'] > 0) {
				unmatched--;
			}
			freq[s2[right] - 'a']--;
			if (right - left + 1 == s1.size()) {
				if (unmatched == 0) {
					return true;
				}
				freq[s2[left] - 'a']++;
				if (freq[s2[left] - 'a'] > 0) {
					unmatched++;
				}
				left++;
			}
		}
		return false;
	}
};
/*
s1 = a b c
s2 = d c a b e

substring -> sliding window (fixed window)

vector<int> freq(26, 0)
unmatched = s1.size
init freq based on s1
left = 0
for (right = 0; right < s2.size(); right++)
	update unmatched & freq 
	if (right - left + 1 == s1.size())
		if unmatched == 0
			return true
		update unmatched & freq
		left++
return false
*/