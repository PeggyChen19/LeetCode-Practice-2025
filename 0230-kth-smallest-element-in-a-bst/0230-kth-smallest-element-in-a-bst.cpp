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
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        inOrder(root, k, ans);
        return ans;
    }
private:
    bool inOrder(TreeNode* node, int& k, int& ans) {  // return if found kth or not
        if (!node) return false;
        // left
        if (inOrder(node->left, k, ans)) return true; // left part has found -> early return 
        // root
        k--;
        if (k == 0) {
            ans = node->val;
            return true;
        }
        // right
        return inOrder(node->right, k, ans);
    }
};
/*
use inorder (left->root->right) can traverse the BST from small to big
Time: O(k)
Space: O(h)
*/