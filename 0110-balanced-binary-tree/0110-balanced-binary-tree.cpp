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
	bool isBalanced(TreeNode* root) {
		return (calculateDepth(root) == -1) ? false : true;
	}
private:
	int calculateDepth(TreeNode* node) {
		if (!node) {
			return 0;
		}
		int left = calculateDepth(node->left);
		int right = calculateDepth(node->right);
		if (left == -1 || right == -1 || abs(left - right) > 1) { // not balanced
			return -1;
		}
		return max(left, right) + 1;
	}
};
/*
For each node, |depth(node->left) - depth(node->right)| <= 1
Recursion (DFS)
Stop condition: node == null -> depth = 0
*/