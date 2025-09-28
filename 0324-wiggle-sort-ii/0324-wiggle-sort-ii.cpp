class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted = sorting(nums);        
        int mid = nums.size() / 2; // find mid
        if(nums.size() % 2 == 0) mid--;
        int end = nums.size() - 1;
        for(int i = 0; i < nums.size(); i++){
            if(i % 2 == 0){
                nums[i] = sorted[mid];
                mid--;
            }
            else{
                nums[i] = sorted[end];
                end--;
            }
        }
    }
    vector<int> sorting(vector<int> v){
        sort(v.begin(), v.end());
        return v;
    }
};