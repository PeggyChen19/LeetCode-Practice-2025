class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans(size, 1); // pre-allocate vector 
        for (int i = 1; i < size; i++) { // prefix
            ans[i] = ans[i-1] * nums[i-1];
        }
        int suffix = 1;
        for (int j = (size-1); j >= 0; j--) { //suffix
            ans[j] *= suffix;
            suffix *= nums[j];
        }
        return ans;
    }
};
/*
clarify:
the min length of nums -> 2

define:
prefix[i] = prefix[0] * ... * prefix[i-1]
suffix[i] = suffix[the end] * ... * suffix[i+1]
0 1 2 ... size-2 size-1

create ans vector
add "1" to ans as prefix // initialization
go through nums
update prefix
go through nums reversely
calculate suffix and product with prefix
return ans
*/