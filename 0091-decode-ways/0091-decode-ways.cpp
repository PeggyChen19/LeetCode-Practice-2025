class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') { // invalid
            return 0;
        }
        int back_two = 1, back_one = 1;
        for (int i = 1; i < s.size(); i++) {
            int cur;
            if (s[i] == '0') {
                if (s[i-1] != '1' && s[i-1] != '2') { // invalid
                    return 0;
                } else { // it must combine with previous one
                    cur = back_two;
                }
            } else if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')) { // i can be combine with previous one
                cur = back_two + back_one;
            } else { // i must be individual
                cur = back_one;
            }
            back_two = back_one;
            back_one = cur;
        }
        return back_one;
    }
};
/*
60 -> 0
206 -> 1
13425 -> 4
1 3 4 2 5
1 3 4 25
13 4 2 5
13 4 25

State: index
Sub-solution: the possbile decoded ways until current index
Decision:
For an index, it can choose to:
1. combine with the previous one (the number should between 10~26)
2. be individual
Transition function:
f(i) = f(i-1) // i must be individual
f(i) = f(i-2) // i must combine
f(i) = f(i-2) + f(i-1) // i can combine or be individual
f(i) = 0 // i is zero && i-1 != 1 && i-1 != 2
Base case:
f(-1) = 1
f(0) = 1
Implement: Use a for loop
Memorization: Use 2 var to record back_one & back_two
*/