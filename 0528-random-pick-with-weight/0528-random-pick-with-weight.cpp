class Solution {
public:
	int sum;
	vector<int> wRange; // 1 ~ sum
	Solution(vector<int>& w) {
        srand(time(NULL));
		int cur = 0;
		for (int i = 0; i < w.size(); i++) {
			cur += w[i];
			wRange.push_back(cur);
		}
		sum = cur;
	}
	
	int pickIndex() {
		int min = 1, max = sum; // the same range as wRange
		int x = rand() % (max - min + 1) + min;
		return binarySearch(x);
	}
private:
	int binarySearch(int& x) {
		int left = 0, right = wRange.size();
		while (left <= right) {
			int mid = left + (right - left) / 2;
			int preWeight = (mid == 0) ? 0 : wRange[mid - 1];
			if (x > preWeight && x <= wRange[mid]) { // valid
				return mid;
			} else if (x <= preWeight) { // go left
				right = mid - 1;
			} else { // go right
				left = mid + 1;
			}
		}
		return -1; // should be impossible
	}
};

/*
vector range
w = 3 1 2
range = 3 4 6 //the range of i: range[i-1]+1 ~ range[i]

int sum = sum(w)
randomly pick an number from 1 ~ sum
how to know the corresponding index of this number?
binary search!
*/