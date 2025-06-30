class Solution {
public:
    string intToRoman(int num) {
        string result = "";
        vector<pair<int, string>> roman = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };
        for (auto& [val, symbol] : roman) {
            while (num >= val) {
                result += symbol;
                num -= val;
            }
        }
        return result;
    }
};
/*
1 <= num <= 3999
set a vector to record val: symbol
convert val to symbol from big to small
*/