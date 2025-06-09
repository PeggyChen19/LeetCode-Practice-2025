class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long, int> prefixSums; // sum, count
        prefixSums[0] = 1;
        long curSum = 0;
        return dfs(root, targetSum, curSum, prefixSums);
    }
private:
    int dfs(TreeNode* node, int& target, long& curSum, unordered_map<long, int>& prefixSums) {
        if (!node) return 0;
        curSum += node->val;
        int count = prefixSums[curSum - target];
        prefixSums[curSum]++;
        count += dfs(node->left, target, curSum, prefixSums);
        count += dfs(node->right, target, curSum, prefixSums);
        prefixSums[curSum]--;
        curSum -= node->val;
        return count;
    }
};
/*
Path: from top to down, don't need to start from root
Need to explore all possiblities: DFS (pre-order)
Start from different nodes makes it difficult, we can utilize prefixSums & curSum
prefixSums: record sums from root to nodes before cur node
(backtracking before we go to different path)
curSum: sum from root to cur node
if (curSum - prefixSum ==  target) find valid path
*/