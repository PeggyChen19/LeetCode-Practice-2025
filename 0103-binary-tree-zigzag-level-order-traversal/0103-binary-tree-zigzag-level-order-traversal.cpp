class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> results;
        bool reversed = false;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> layerNodes(size);
            for (int i = 0; i < size; i++) { // the same layer
                TreeNode* cur = q.front();
                q.pop();
                int ind = reversed ? size - 1 - i : i;
                layerNodes[ind] = cur->val;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            reversed = !reversed;
            results.push_back(layerNodes);
        }
        return results;
    }
};
/*
We need to traverse layer by layer
BFS based (root -> left -> right), use queue (reverse for odd layer)
Improvement: Not use reverse -> utilize the size of each layer
*/