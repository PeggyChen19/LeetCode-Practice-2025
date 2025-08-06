class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return valid(root, NULL, NULL);        
    }
private:
    bool valid(TreeNode* node, TreeNode* minNode, TreeNode* maxNode) {
        if (!node) return true;
        if ((minNode && node->val <= minNode->val) || (maxNode && node->val >= maxNode->val)) return false;
        return valid(node->left, minNode, node) && valid(node->right, node, maxNode);
    }
};