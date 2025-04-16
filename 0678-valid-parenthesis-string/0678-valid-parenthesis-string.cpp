class Solution {
public:
	bool checkValidString(string s) {
		int min_left = 0, max_left = 0;
		for (char c : s) {
			if (c == '(') {
				min_left++;
				max_left++;
			} else if (c == ')') {
				min_left--;
				max_left--;
			} else { // *
				min_left--; // might be right
				max_left++; // might be left
			}
			if (max_left < 0) { // need more left 
				return false;
			}
			if (min_left < 0) { // * can't be right for now
				min_left = 0;
			}
		}
		return min_left == 0 ? true : false;
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
