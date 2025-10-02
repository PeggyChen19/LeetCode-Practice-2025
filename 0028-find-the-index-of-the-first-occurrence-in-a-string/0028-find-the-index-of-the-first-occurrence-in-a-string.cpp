class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i < haystack.size(); i++) {
            int a = i, b = 0;
            while (b < needle.size() && haystack[a] == needle[b]) {
                a++;
                b++;
            }
            if (b == needle.size()) return i;
        }
        return -1;
    }
};