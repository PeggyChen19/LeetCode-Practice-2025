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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (isSameTree(root, subRoot)) {
            return true;
        }
        if(!root || !subRoot) {
            return (root == subRoot);
        }
        return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
    }
    bool isSameTree(TreeNode* a, TreeNode*b) {
        if (!a || !b) {
            return (a == b);
        }
        if(a->val != b->val) {
            return false;
        }
        return (isSameTree(a->left, b->left) && isSameTree(a->right, b->right));
    }
};