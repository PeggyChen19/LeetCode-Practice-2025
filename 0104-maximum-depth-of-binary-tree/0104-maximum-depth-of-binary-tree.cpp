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
    int maxDepth(TreeNode* root) {
        int depth = 0;
        return dfs(root, depth);
    }
    int dfs(TreeNode* root, int depth) {
        if (root) {
            depth++;
            return max( dfs(root->left, depth), dfs(root->right, depth) );
        } else {
            return depth;
        }
    };
};

/*
maximum depth -> the farest node -> DFS
use recursion to achieve it
depth adds one if root is not null
recur left
recur right
*/