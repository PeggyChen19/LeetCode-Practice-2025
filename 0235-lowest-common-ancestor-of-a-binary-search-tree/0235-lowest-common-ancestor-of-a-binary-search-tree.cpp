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
        queue<TreeNode*> tree_queue;
        tree_queue.push(root);
        while (!tree_queue.empty()) {
            TreeNode* node = tree_queue.front();
            tree_queue.pop();
            if (!node) {
                continue;
            }
            if (isTargetNode(node->left, p, q) && isTargetNode(node->right, p, q)) {
                return node;
            } else if (isTargetNode(node->left, p, q))) {
                return node->left;
            } else if (isTargetNode(node->right, p, q)) {
                return node->right;
            }
            tree_queue.push(node->left);
            tree_queue.push(node->right);
        }
        return nullptr;
    }
private:
    bool isTargetNode(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (!node) {
            return false;
        }
        return (node->val == p->val || node->val == q->val);
    }
};

/*
The number of nodes >= 2
All Node.val are unique.
p != q, p and q will exist in the BST.

BFS: go into the tree level by level
to check if the descendants of the current node (including itself) contain "at least one" of the target or not
    yes: return the current node
    no: keep going to the lower level

We want to find the lowest node, so the limit will be the highest node -> return when find the higher node
*/
