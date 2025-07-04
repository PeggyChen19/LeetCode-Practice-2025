class Solution {
public:
    bool checkValidString(string s) {
        int minLeft = 0, maxLeft = 0;
        for (char& ch : s) {
            if (ch == '(') {
                minLeft++;
                maxLeft++;
            } else if (ch == '*') {
                minLeft = max(minLeft - 1, 0); // might be right
                maxLeft++; // might be left
            } else { // ')'
                minLeft = max(minLeft - 1, 0);
                maxLeft--;
                if (maxLeft < 0) return false;
            }
        }
        return minLeft == 0;
    }
};
/*
Use two int: leftCount & starCount
( -> leftCount++
) -> leftCount-- OR starCount--
* -> starCount++
return leftCount <= starCount // has problem, e.g. *(

Revised: two int: minLeft, maxLeft
( -> minLeft++, maxLeft++
* -> minLeft--, maxLeft++
) -> minLeft-- (if > 0), maxLeft--
Invalid: maxLeft < 0 during loop
Valid: minLeft == 0
*/