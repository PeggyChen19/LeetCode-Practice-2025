class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        for (int i = 0; i <= n; i++) {
            ans[i] = ans[i >> 1] + (i & 1);
        }
        return ans;
    }
};
/*
0 -> 0
1 -> 1
2 -> 10
3 -> 11
4 -> 100
5 -> 101
我們要想辦法找到說目前的 ans[i] 跟前面 ans[0~i-1] 有什麼關係，這樣就可以推出 ans[i]
i 右移去掉最後一位後（其實就是除 2）這個數肯定已經在前面出現過，所以已知 ans[i >> 1]
如果移掉的是 1，那答案還要再 +1（奇數）
如果移掉的是 0，那答案就等於 ans[i >> 1]
*/