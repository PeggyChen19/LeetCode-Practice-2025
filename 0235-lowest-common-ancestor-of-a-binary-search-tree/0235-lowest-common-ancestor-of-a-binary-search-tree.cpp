/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if (p->val < root->val && q->val < root->val) { // go left
                root = root->left;
            } else if (p->val > root->val && q->val > root->val) { // go right
                root = root->right;
            } else { // the root separate target nodes or the root is one of the target nodes
                return root;
            }
        }
        return nullptr;
    }
};

/*
we can utilize the characteristics of BST
we can keep going to the subtree which contains both target node
if we can't find this subtree, it means that the current node seperates the two target nodes OR 
the current node is one of the target nodes -> current node will be the LCA
*/