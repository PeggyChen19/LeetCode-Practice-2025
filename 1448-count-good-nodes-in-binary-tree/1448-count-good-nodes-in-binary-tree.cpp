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
    int goodNodes(TreeNode* root) {
        return inorder(root, INT_MIN);
    }
private:
    int inorder(TreeNode* node, int curMax) {
        if (!node) {
            return 0;
        }
        int goodNode = (node->val >= curMax) ? 1 : 0;
        curMax = max(node->val, curMax);
        return goodNode + inorder(node->left, curMax) + inorder(node->right, curMax);
    }
};
/*
Good Node: no greater node on the path

In-order go through all nodes  -> recursion
Record the max value until now
*/