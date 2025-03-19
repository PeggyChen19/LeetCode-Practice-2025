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
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }
        return ( valid(root->left, LONG_MIN, root->val) && valid(root->right, root->val, LONG_MAX) );
    }
private:
    bool valid(TreeNode* node, long min, long max) {
        if (!node) {
            return true;
        }
        if (node->val > min && node->val < max) { // valid for the current node -> go to left and right sub nodes
            return valid(node->left, min, node->val) && valid(node->right, node->val , max);
        } else {
            return false;
        }
    }
};

/*
recursively check the whole tree
use min & max range to control the values in subtrees
*/