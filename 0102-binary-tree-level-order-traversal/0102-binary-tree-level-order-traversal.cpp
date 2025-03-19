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
        bfs_q.push(nullptr);
        ans.push_back({});
        while (!bfs_q.empty()) {
            TreeNode* node = bfs_q.front();
            bfs_q.pop();
            if (node) {
                (ans[ans.size()-1]).push_back(node->val);
                if (node->left) {
                    bfs_q.push(node->left);
                }
                if (node->right) {
                    bfs_q.push(node->right);
                }
            } else if (!bfs_q.empty()){ // seperator
                bfs_q.push(nullptr);
                ans.push_back({});
            }
        }
        return ans;
    }
};

/*
level by level -> BFS (queue)
for diff level, diff vector -> we need to add seperator (nullptr)
*/