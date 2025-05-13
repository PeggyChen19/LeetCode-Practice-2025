class Solution {
public:
	bool isNStraightHand(vector<int>& hand, int groupSize) {
		if (hand.size() % groupSize) { // early return
			return false;
		}
		map<int, int> frequency;
		for (int& card : hand) {
			frequency[card]++;
		}
		for (auto& [num, count] : frequency) {
			if (count > 0) {
				int min_count = count;
				for (int i = 0; i < groupSize; i++) { // the whole group must have at least min count
					if (frequency[num + i] < min_count) {
						return false;
					} else {
						frequency[num + i] -= min_count;
					}
				}
			}
		}
		return true;
	}
};
/*
consecutive -> sort
use map to record all cards and their frequency -> sort automatically
keep looping the map and checking if it can make a group
*/