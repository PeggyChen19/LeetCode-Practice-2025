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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int dL = countDepth(root->left);
        int dR = countDepth(root->right);
        if (dL == dR) {
            return ((1 << dL) - 1) + 1 + countNodes(root->right);
            // 2^h == 1 << h
            // +1 is the root
        } else {
            return ((1 << dR) - 1) + 1 + countNodes(root->left);
        }
    }
private:
    int countDepth(TreeNode* node) {
        if (!node) return 0;
        return 1 + countDepth(node->left);
    }
};
/*
keep dividing the tree into two subtree (left & right)
at least one of the subtrees will be perfect (full) tree 
calculate the perfect tree nodes via formula 2^h - 1
recursion another tree

how to know if the tree is perfect or not? 
check the leftmost depth
depth(left) == depth(right) -> left must be perfect tree
depth(left) != depth(right) -> right must be perfect tree

    1
   /\
  2  3
 /
4

    1
   / \
  2   3
 / \  /
4  5  6
*/