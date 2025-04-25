class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while (left != right) {
            int sum = numbers[left] + numbers[right];
            if (sum < target)
                left++;
            else if (sum > target)
                right--;
            else
                return {left + 1, right + 1};
        }
        return {0, 0};
    }
};
/*
1 3 5 9, target=6 -> ans: {1, 3}
two pointers -> start from left and right seperately

left = the first element, right = the last element
while (left != right)
    if left+right < target
        left++
    elif left+right > target
        right--
    else
        return {left,right}
*/