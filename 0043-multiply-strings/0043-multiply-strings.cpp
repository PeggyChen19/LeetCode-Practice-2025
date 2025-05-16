class Solution {
public:
    string multiply(string num1, string num2) {
        if (nums1 == "0" || nums2 == "0") {
            return "0";
        }
        int len1 = num1.size(), len2 = num2.size();
        vector<int> result(len1 + len2, 0);
        for (int i = len1-1; i >= 0; i--) {
            for (int j = len2-1; j >= 0; j--) {
                result[i+j+1] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        for (int i = len1+len2-1; i > 0; i--) {
            result[i-1] += (result[i] / 10);
            result[i] %= 10;
        }
        string ans = "";
        for (int i = 0; i < len1+len2; i++) {
            if (ans == "" && result[i] == 0) { // ignore leading zero
                continue;
            }
            ans += to_string(result[i]);
        }
        return ans == "" ? "0" : ans;
    }
};
/*
at most len1 + len2 digits
for nums[i] * nums[j] -> store in i+j+1 (because it's 0 indexed)
    0 1 2
    1 2 3
      4 5
----------
    * * *
  * * *  
----------
0 1 2 3 4
Create a result vector and then handle the carries after calculating all digits
*/