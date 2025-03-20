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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int ans = -1;
        inOrderTraverse(root, k, count, ans);
        return ans;
    }
private:
    void inOrderTraverse(TreeNode* root, int k, int& count, int& ans) {
        if (!root) {
            return;
        }
        inOrderTraverse(root->left, k, count, ans);
        count++;
        if (count == k ){
            ans = root->val;
            return;
        }
        inOrderTraverse(root->right, k, count, ans);
    }
};

/*
BST -> sorted array when we traverse via in-order (left root right)
We can use recursion and record the ?th smallest value node
T: O(n) / S: O(h)
*/