class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return valid(root, LONG_MIN, LONG_MAX);        
    }
private:
    bool valid(TreeNode* node, long minVal, long maxVal) {
        if (!node) return true;
        if (node->val <= minVal || node->val >= maxVal) return false;
        return valid(node->left, minVal, node->val) && valid(node->right, node->val, maxVal);
    }
};