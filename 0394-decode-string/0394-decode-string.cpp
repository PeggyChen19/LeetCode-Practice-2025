class Solution {
public:
    string decodeString(string s) {
        return buildString(s, 1);
    }
private:
    string buildString(string s, int k) {
        string result = "";
        int i = 0;
        while (i < s.size()) {
            int k = 0;
            while (s[i] >= '0' && s[i] <= '9') {
                k = k * 10 + (s[i] - '0');
                i++;
            }
            if (k > 0) { // valid k
                int start = i + 1; // skip [
                int unmatched = 0;
                do {
                    if (s[i] == '[') unmatched++;
                    if (s[i] == ']') unmatched--;
                    i++;
                } while (unmatched);
                int end = i - 2; // i will stop at the first element after ], go back to the end of sub string
                string repeated = buildString(s.substr(start, (end - start + 1)), k);
                for (int j = 0; j < k; j++) {
                    result += repeated;
                }
            } else {
                result += s[i];
                i++;
            }
        }
        return result;
    }
};
/*
nested structure -> recursion
0 1 2 3 4 5 6
4 [ a b c ]
    s       i
string buildString(string s, int k)
    string result = ""
    i = 0
    while (i < s.size())
        if s[i] is digit
            // get the repeated_sub_string (without [])
            result += buildString(repeated_sub_string, digit)
        else
            result += s[i]
        i++
    return result
*/