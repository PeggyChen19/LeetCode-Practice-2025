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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> bfs_q;
        if (!root) {
            return ans;
        }
        bfs_q.push(root);
        while (!bfs_q.empty()) {
            int level_size = bfs_q.size();
            vector<int> level;
            for (int i = 0; i < level_size; i++) { // record current level and put all next-level nodes
                TreeNode* node = bfs_q.front();
                bfs_q.pop();
                level.push_back(node->val);
                if (node->left) {
                    bfs_q.push(node->left);
                }
                if (node->right) {
                    bfs_q.push(node->right);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};

/*
level by level -> BFS (queue)
for diff level, diff vector -> record the current queue size (= level size) before insert the next level
*/