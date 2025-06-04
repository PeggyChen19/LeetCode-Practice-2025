struct CustomCompare {
    bool operator()(const string& a, const string& b) const {
        return (a + b) > (b + a);
    }
};
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string result = "";
        vector<string> strNums;
        for (auto& num : nums) {
            strNums.push_back(to_string(num));
        }
        sort(strNums.begin(), strNums.end(), CustomCompare());
        if (strNums.empty() || strNums[0] == "0") {
            return "0";
        }
        for (auto& strNum : strNums) {
            result += strNum;
        }
        return result;
    }
};
/*
We need to sort nums in some special rules
99, 900 -> 99 go first
987, 9876 -> 987 go first (9879876 > 9876987)
123, 1234 -> 1234 go first (1234123 > 1231234)
Based on string compare, but not simply compare s1 & s2 -> s1+s2 & s2+s1
*/