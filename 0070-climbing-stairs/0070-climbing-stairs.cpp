class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        }
        int back_two = 1;
        int back_one = 2;
        for (int i = 3; i <= n; i++) {
            int tmp = back_one;
            back_one = back_two + back_one;
            back_two = tmp;
        }
        return back_one;
    }
};

/*
to reach n: from n-1 and then go 1 OR from n-2 and then go 2
f(n) = f(n-1) + f(n-2)
f(1) = 1
f(2) = 2
we can actually only record two values f(n-1) & f(n-2)
use a loop to go through all stairs
*/