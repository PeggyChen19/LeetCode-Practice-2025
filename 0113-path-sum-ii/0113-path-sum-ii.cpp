class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        if (!root) return result;
        vector<int> path;
        path.push_back(root->val);
        dfs(root, targetSum - (root->val), path, result);
        return result;
    }
private:
    void dfs(TreeNode* node, int remain, vector<int>& path, vector<vector<int>>& result) {
        if (!node->left && !node->right && !remain) result.push_back(path);
        vector<TreeNode*> children = {node->left, node->right};
        for (auto& child : children) {
            if (child) {
                int val = child->val;
                path.push_back(val);
                dfs(child, remain - val, path, result);
                path.pop_back();
            }
        }
    }
};
/*
root to leaf (no children)

DFS until leaf
Recursive DFS (remain, pathVect)
    return condition: node is leaf && remain == 0
    dfs(node->left)
    backtracking
    dfs(node->right)
    backtracking
*/