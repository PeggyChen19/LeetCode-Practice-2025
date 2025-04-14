class Solution {
public:
    int getSum(int a, int b) {
        while (a != 0) {
            int tmp_a = a;
            a = (a & b) << 1; // and, left shift
            b = (tmp_a ^ b); // xor
        }
        return b;
    }
};
/*
用 and 又 << 的原因：如果兩個都有 1 的話要進位
用 xor 的原因：相異的話就是 1（相當於相加效果），都是 0 就保持 0，都是 1 也保持 0，因為 and 有處理這情況了
直到 and 後為 0，代表沒有要再進位了，答案就會是 xor

 110
 101
-----
1000 (and left shift)
 011 (xor)
----------
0000 (and)
1011 (xor)
*/