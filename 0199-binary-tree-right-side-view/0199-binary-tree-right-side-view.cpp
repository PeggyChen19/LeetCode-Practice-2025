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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> results;
        dfs(root, 0, results);
        return results;
    }
private:
    void dfs(TreeNode* node, int level, vector<int>& results) {
        if (!node) return;
        if (results.size() == level) {
            results.push_back(node->val);
        }
        dfs(node->right, level+1, results);
        dfs(node->left, level+1, results);
    }
};
/*
  1
2   3
   4 5
135
    1
  2   3
4
134

for each level -> find the right most node
can we prune the tree? Check right subtree first
DFS -> recursion
dfs(node, level)
    if results[level] not exist
        push node
    dfs(node->right)
    dfs(node->left)
*/