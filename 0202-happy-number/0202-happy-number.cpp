class Solution {
public:
    bool isHappy(int n) {
        int fast = n, slow = n;
        while (true) {
            fast = process(process(fast));
            slow = process(slow);
            if (fast == 1) return true;
            if (fast == slow) return false;
        }
    }
private:
    int process(int n) {
        int newN = 0;
        while (n > 0) {
            int digit = n % 10;
            newN += digit * digit;
            n /= 10;
        }
        return newN;
    }
};
/*
we need to detect the cycle except "1" -> fast & slow pointers (will meet each other if there is a cycle)
helper function:
int process(int n)
    int newN = 0;
    while (n > 0)
        digit = n % 10
        newN += digit * digit
        n /= 10
    return newN

fast = n
slow = n
while (true)
    fast = process(process(fast))
    slow = process(slow)
    if (fast == 1) return true
    if (fast == slow) reuturn false

9....9 (10 9s)
81 * 10 = 810 -> won't overflow 
*/