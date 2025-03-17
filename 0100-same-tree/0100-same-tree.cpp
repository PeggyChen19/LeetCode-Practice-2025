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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }
        if (!p || !q || p->val != q->val) {
            return false;
        }
        bool left_same = isSameTree(p->left, q->left);
        bool right_same = isSameTree(p->right, q->right);
        if (left_same && right_same) {
            return true;
        } else {
            return false;
        }
    }
};

/*
we need to go trough the whole tree -> use pre-order (recursion)
func recur(a, b)
    check if root_a == root_b
    left_same = recur(a->left, b->left)
    right_same = recur(a->right, b->right)
    return based on left_same & right_same
*/