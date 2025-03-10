class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, maxAns = 0;
        while (left < right) {
            maxAns = max( maxAns, ( (right - left) * min(height[left], height[right]) ) );
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxAns;
    }
};

/*
container = (right-left) * min(height[left], height[right])
為了達到最大容積，two components 都要盡量大，一開始可以先從底最大開始，但是此時高不一定會大，若要減少底，卻能夠獲得更大的容積，那這樣 min(height[left], height[right]) 要越大越好，所以就使用 two pointers 往有潛力的方向移動（移動 height 較低的那邊，找找看有沒有其他更高的數值），在移動過程中一邊紀錄最大的可能值，直到兩指標相撞
當兩個 height 相同時，移動誰都沒關係，因為只有比較短的那邊會影響，移動哪邊都不影響策略

create left = beginning, right = end, maxAns = 0
while (left < right)
    maxAns = max(maxAns, (right - left) * min(height[left], height[right]))
    if (height[left] < height[right])
        left++
    else
        right--
return maxAns

*/