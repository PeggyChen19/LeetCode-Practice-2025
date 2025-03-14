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
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
private:
    void invert(TreeNode* node) {
        if (!node) {
            return;
        }
        TreeNode* tmp_right = node->right;
        node->right = node->left;
        node->left = tmp_right;
        invert(node->right);
        invert(node->left);
    }
};
/*
recursive fun invert
    if root == null
        return
    swap left and right
    invert(left)
    invert(right)
*/