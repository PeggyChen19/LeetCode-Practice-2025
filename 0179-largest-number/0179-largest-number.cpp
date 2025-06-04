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