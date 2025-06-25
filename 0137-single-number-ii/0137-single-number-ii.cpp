class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int once = 0, twice = 0;
        for (int& num : nums) {
            once = (once ^ num) & ~twice; // exclude those bits appear twice
            twice = (twice ^ num) & ~once; // exclude those bits appear once
        }
        return once;
    }
};
/*
1 num: appears once, other nums: appears 3 times 
Time: O(n), Space: (1)

初始想法：Bit manipulation (XOR)? not work, we can't tell the difference between 1 or 3 times
初始想法：Sum up nums and mod 3? not work, for nums which can divide by 3 itself, we can't filter out it

修正：Sum up nums in bit level and then mod 3 
How? 每個 int 都是由 32 bits 組成，所以可以用來記錄每個 bit 的狀態 -> use two int: once & twice
times once twice
0     0    0
1     1    0
2     0    1
once = (once ^ num) & ~twice
^：只考慮剛好一個 1 的情況，兩個 1 在 twice 處理
& ~twice：once 和 twice 不會同時為 1
twice = (twice ^ num) & ~once
^：兩個 1（2+1=3）或沒有 1 都是歸零
& ~once：once 和 twice 不會同時為 1
*/