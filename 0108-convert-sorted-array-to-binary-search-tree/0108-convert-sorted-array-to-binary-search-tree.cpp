/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        return buildTree(nums, 0, nums.size() - 1);
    }
private:
    TreeNode* buildTree(vector<int>& nums, int start, int end) {
        if (start > end) return nullptr;
        if (start == end) return new TreeNode(nums[start]);
        int mid = start + (end - start) / 2;
        TreeNode* center = new TreeNode(nums[mid], buildTree(nums, start, mid - 1), buildTree(nums, mid + 1, end));
        return center;
    }
};
/*
height-balanced -> nearly the same numbers of nodes in left & right trees
recursion
    find the center
    if center is leaf -> return center
    center->left = recursion(start ~ center-1)
    center->right = recursion(center+1 ~ end)
    return center
*/