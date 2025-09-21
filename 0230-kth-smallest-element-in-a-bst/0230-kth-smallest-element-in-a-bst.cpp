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
        int cur = 0;
        return inOrder(root, k, cur);
    }
private:
    int inOrder(TreeNode* node, int& k, int& cur) {
        if (!node) return -1;
        // left
        int leftVal = inOrder(node->left, k, cur);
        if (leftVal != -1) return leftVal;
        // root
        cur++;
        if (cur == k) return node->val;
        // right
        int rightVal = inOrder(node->right, k, cur);
        return rightVal; // -1 or real val
    }
};
/*
use inorder (left->root->right) can traverse the BST from small to big
Time: O(k)
Space: O(h)

return inOrder(root, k, cur)

int inOrder(TreeNode* node, int& k, int& cur)
    if (!node) return -1
    // left
    int leftVal = inOrder(node->left, k, cur)
    if (leftVal != -1) return leftVal
    
    // root
    cur++;
    if (cur == k) return node->val

    // right
    the same logic as left
    
    return -1 // haven't found target
*/