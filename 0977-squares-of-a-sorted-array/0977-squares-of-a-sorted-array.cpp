class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result;
        int size = nums.size();
        int pos = size;
        for (int i = 0; i < size; i++) {
            if (nums[i] >= 0) {
                pos = i;
                break;
            }
        }
        int neg = pos - 1;
        while (neg >= 0 && pos < size) {
            int negSquare = nums[neg] * nums[neg];
            int posSquare = nums[pos] * nums[pos];
            if (negSquare < posSquare) {
                result.push_back(negSquare);
                neg--;
            } else {
                result.push_back(posSquare);
                pos++;
            }
        }
        while (neg >= 0) {
            result.push_back(nums[neg] * nums[neg]);
            neg--;
        }
        while (pos < size) {
            result.push_back(nums[pos] * nums[pos]);
            pos++;
        }
        return result;
    }
};
/*
-3 -1 0 2 4
9 1 0 4 16
from the first element >= 0, go left and go right respectively, create the result vecotr in order
*/