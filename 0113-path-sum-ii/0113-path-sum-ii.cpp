class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        if (!root) return result;
        vector<int> path;
        dfs(root, targetSum, path, result);
        return result;
    }
private:
    void dfs(TreeNode* node, int remain, vector<int>& path, vector<vector<int>>& result) {
        if (!node) return;
        path.push_back(node->val);
        remain -= node->val;
        if (!node->left && !node->right && !remain) result.push_back(path);
        dfs(node->left, remain, path, result);
        dfs(node->right, remain, path, result);
        path.pop_back();
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