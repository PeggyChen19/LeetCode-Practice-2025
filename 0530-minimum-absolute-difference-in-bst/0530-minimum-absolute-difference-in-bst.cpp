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
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX, prev = -1;
        inOrder(root, prev, ans);
        return ans;
    }
private:
    void inOrder(TreeNode* node, int& prev, int& ans) {
        if (!node) return;
        inOrder(node->left, prev, ans);
        if (prev != -1) {
            ans = min(ans, node->val - prev);
        }
        prev = node->val;
        inOrder(node->right, prev, ans);
    }
};
/*
BST -> can traverse the tree in a sorted order -> inorder
*/