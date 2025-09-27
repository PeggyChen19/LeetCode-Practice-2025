class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        if (denominator == 0) return "invalid";
        bool negative = ((numerator < 0) ^ (denominator < 0)) ? true : false;
        long long n = llabs(numerator);
        long long d = llabs(denominator);

        long long integer = n / d;
        long long remainder = n % d;
        string result = negative ? "-" : "";
        result += to_string(integer);
        if (remainder == 0) return result;
        else result.push_back('.');

        unordered_map<int, int> mapping; // remainder: index
        while (remainder != 0) {
            if (mapping.count(remainder)) {
                int pos = mapping[remainder];
                result.insert(pos, 1,'(');
                result.push_back(')');
                return result;
            }
            mapping[remainder] = result.size();
            remainder *= 10;
            int digit = remainder / d;
            remainder %= d;
            result.push_back(char('0' + digit));
        }
        return result;
    }
};
/*
"remainder" makes the float digit repeat, not the digit itself
use unordered_map to record {remainder, index} pair, when found the same remainder -> insert '('

4/333
integer = 0
remainder = 40
*/