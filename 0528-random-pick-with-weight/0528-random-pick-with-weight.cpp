class Solution {
public:
	int totalSum;
	vector<int> prefixSums; // 1 ~ totalSum

	Solution(vector<int>& w) {
        srand(time(NULL));
		totalSum = 0;
		for (int i = 0; i < w.size(); i++) {
			totalSum += w[i];
			prefixSums.push_back(totalSum);
		}
	}
	
	int pickIndex() {
		int min = 1, max = totalSum; // the same range as prefixSums
		int target = rand() % (max - min + 1) + min;
		return binarySearch(target);
	}
private:
	int binarySearch(int& target) { // find the index <= target
		int left = 0, right = prefixSums.size() - 1;
        int result = -1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (target <= prefixSums[mid]) { // go left
                result = mid; // probably valid -> update result
                right = mid - 1;
			} else { // go right
                left = mid + 1;
            }
		}
		return result;
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