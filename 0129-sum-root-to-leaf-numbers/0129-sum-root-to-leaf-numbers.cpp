class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int totalSum = 0;
        dfs(root, 0, totalSum);
        return totalSum;
    }
private:
    void dfs(TreeNode* node, int curSum, int& totalSum) {
        if (!node) return;
        curSum = curSum * 10 + node->val;
        if (!node->left && !node->right) { // leaf
            totalSum += curSum;
            return;
        } else {
            dfs(node->left, curSum, totalSum);
            dfs(node->right, curSum, totalSum);
        }
    }
};
/*
DFS go through all nodes
When recursive into a new node: curSum = curSum * 10 + nodeVal
When entering a leaf node: totalSum += curSum
*/
