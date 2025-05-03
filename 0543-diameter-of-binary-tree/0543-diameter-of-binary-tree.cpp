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
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        dfs(root, result);
        return result;
    }
private:
    int dfs(TreeNode* node, int& result) {
        if (!node) {
            return 0;
        }
        int right_depth = dfs(node->right, result);
        int left_depth = dfs(node->left, result);
        result = max(result, right_depth + left_depth);
        return max(right_depth, left_depth) + 1;
    }
};
/*
for each node, record the right_depth and left_depth
the max (right_depth + left_depth) will be the answer

    1
   / \
  2   3
 / \
4   5
     \
      6

Method:
use dfs and record the level from bottom
int dfs(node)
    if (!node)
        return 0
    int right = dfs(node->right)
    int left = dfs(node->left)
    global_max = max(global_max, right+left)
    return max(right, left) + 1;
*/