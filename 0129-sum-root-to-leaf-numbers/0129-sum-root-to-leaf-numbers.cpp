class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
private:
    int dfs(TreeNode* node, int curSum) {
        if (!node) return 0;
        curSum = curSum * 10 + node->val;
        if (!node->left && !node->right) return curSum; // leaf
        return dfs(node->left, curSum) + dfs(node->right, curSum);
    }
};
/*
DFS recursion:
    curSum = curSum * 10 + nodeVal
    When entering a leaf node: return curSum
    return dfs(left) + dfs(right)
*/