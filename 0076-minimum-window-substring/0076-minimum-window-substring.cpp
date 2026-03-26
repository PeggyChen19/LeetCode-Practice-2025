class Solution {
public:
    string minWindow(string& s, string& t) {
        unordered_map<char, int>freq;
        int minLen = INT_MAX;
        int start = -1;

        for(char c : t){
            freq[c]++;
        }

        int require = t.size();
        int left = 0;
        int right = 0;
        while(right < s.size()){
            char c = s[right];

            if(freq.count(c)){
                if(freq[c] > 0) require--;
                freq[c]--;
            }

            while(require == 0){
                int len = right - left + 1;
                if(require == 0 && len < minLen){
                    minLen = len;
                    start = left;
                }
                char l = s[left];
                if(freq.count(l)){
                    if(freq[l] >= 0) require++;
                    freq[l]++;
                }
                left++;
            }

            right++;
        }
        return (minLen != INT_MAX) ? s.substr(start, minLen) : "";
    }
};


