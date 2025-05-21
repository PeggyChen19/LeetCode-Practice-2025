class Solution {
public:
    bool isHappy(int n) {
        int fast = n, slow = n;
        do {
            fast = square(square(fast));
            slow = square(slow);
        } while (fast != slow);

        return slow == 1;
    }   
private:
    int square(int num) {
        int result = 0;
        while (num) {
            result += (num % 10) * (num % 10);
            num /= 10;
        }
        return result;
    }
};
/*
How to know if we enter a cycle? 
Do we need to record all the numbers?
No -> we can use fast & slow pointers to detect cycle
*/