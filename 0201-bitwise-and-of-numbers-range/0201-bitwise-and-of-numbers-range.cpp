class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {        
        int shift = 0;
        while (left != right) {
            left >>= 1;
            right >>= 1;
            shift++;
        }
        return left << shift;
    }
};
/*
0101
0110
0111
1000

For a position, final AND result is 1 only when all nums have 1 at this position
-> go from x to x+1: flip the rightmost 0 to 1, and reset all less significant bits to 0
-> our target: find the common prefix (in binary)
1. compare left & right
2. if not the same -> both right shift
3. repeate 1.2. until left == right
4. return the common prefix
*/