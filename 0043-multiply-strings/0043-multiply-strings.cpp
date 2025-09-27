class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        string result = "";
        int size1 = num1.size(), size2 = num2.size();
        for (int i = 0; i < size1 + size2; i++) {
            result.push_back('0'); // init result
        }
        for (int i = size1 - 1; i >= 0; i--) {
            int a = num1[i] - '0';
            for (int j = size2 - 1; j >= 0; j--) {
                int b = num2[j] - '0';
                int sum = (result[i + j + 1] - '0') + a * b; 
                result[i + j + 1] = char('0' + (sum % 10));
                result[i + j] = char(result[i + j] + sum / 10); // it might > '9', but it will fix (mod) later
            }
        }
        int start = 0;
        while (start < result.size() && result[start] == '0') {
            start++;
        }
        return result.substr(start);
    }
};
/*
if num1 or num2 == "0" -> return "0"
rerserve result string size (size1 + size2) with all '0'
carry = 0
for i = size1 - 1; i >= 0; i--
    for j = size2 - 1; j >= 0; j--
        result[i + j + 1] += carry + (nums1[i] * nums2[j] % 10)
        update carry
remove the leading zero 

      0 1 2 (index)
      1 2 3
      1 2 3
  ----------
      3 6 9
    3 6 9
  ----------
x x 4 0 5 9
0 1 2 3 4 5 (index)

     9 9
     9 9
   -----
   8 9 1
 8 9 1
--------

*/