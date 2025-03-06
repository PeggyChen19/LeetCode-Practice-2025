class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans;
        ans.push_back(1); //prefix[0]
        for (int i = 1; i < nums.size(); i++) { // prefix
            ans.push_back(ans[i-1] * nums[i-1]);
        }
        int suffix = nums[size-1];
        for (int j = (size-2); j >= 0; j--) { //suffix
            ans[j] = ans[j] * suffix;
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