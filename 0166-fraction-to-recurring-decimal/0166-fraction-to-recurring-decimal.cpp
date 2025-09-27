/*
detect negative
no remainder: return ans
remainder:
1. record the remainder & posistion 
2. detect repeat remainder
3. insert
4. update remainder
*/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";
        string ans = "";
        if(numerator < 0 ^ denominator < 0) ans += '-';
        long n = abs(numerator);
        long d = abs(denominator);
        
        ans += to_string(n / d);
        long r = n % d;
        if(r == 0) return ans;
        else ans += '.';

        unordered_map<long, long> pos;
        while(r != 0){
            if(!pos.count(r)){
                pos[r] = ans.size();
            }
            else{
                ans.insert(pos[r], "(");
                ans += ')';
                break;
            }
            r *= 10;
            ans += to_string(r / d);
            r %= d;
        }
        return ans;
    }
};