class Solution {
public:
	bool checkValidString(string s) {
		int minL = 0, maxL = 0; // the possible range of (
		for (char c : s) {
			if (c == '(') {
				minL++;
				maxL++;
			} else if (c == ')') {
				minL = max(minL - 1, 0);
				maxL--;
			} else { // *
				minL = max(minL - 1, 0); // might be right
				maxL++; // might be left
			}
			if (maxL < 0) { // need more left 
				return false;
			}
		}
		return minL == 0 ? true : false;
	}
};
/*
valid
()
((*)
invalid
()(

We need to match ( and ) and follow the order
Core question: how to decide what * to be?
( : put into stack, for future ) matching
) : pop the ( in the stack

we can maintain a range of possible "unmatched (" : min ~ max
( : min++, max++
) : min--, max--
* : min--, max++ because it can be ( or ) or empty

invalid situation:
max < 0 during the loop
valid situation:
max == 0 in the end of the loop
*/
