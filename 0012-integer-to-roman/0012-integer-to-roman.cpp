class Solution {
public:
    string intToRoman(int num) {
        if (num < 1 || num > 3999) return "";
        string result = "";
        unordered_map<int, string> roman;
        roman[1] = "I"; roman[5] = "V";
        roman[10] = "X"; roman[50] = "L";
        roman[100] = "C"; roman[500] = "D";
        roman[1000] = "M";
        vector<int> ones = {1000, 100, 10, 1};
        vector<int> fives = {-1, 500, 50, 5};
        for (int i = 0; i < ones.size(); i++) {
            int divide = num / ones[i];
            num %= ones[i];
            if (divide == 4) {
                result += roman[ones[i]] + roman[fives[i]];
            } else if (divide == 9) {
                result += roman[ones[i]] + roman[ones[i - 1]];
            } else {
                if (divide >= 5) {
                    result += roman[fives[i]];
                    divide -= 5;
                }
                for (int j = 0; j < divide; j++) {
                    result += roman[ones[i]];
                }
            }
        }
        return result;
    }
};
/*
1 <= num <= 3999
ones: 1000, 100, 10, 1
fives: 500, 50, 5
for ones
    if num / one > 0
        if num / one == 4: use (one - five)
        if num / one == 5: use five
        else: use multiple ones
*/