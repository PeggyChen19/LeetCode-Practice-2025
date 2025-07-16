class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> levelContent(levelSize);
            for (int i = 0; i < levelSize; i++) { // handle nodes level by level
                TreeNode* node = q.front();
                q.pop();
                levelContent[i] = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            result.push_back(levelContent);
        }
        return result;
    }
};
/*
level by level -> BFS with queue
*/