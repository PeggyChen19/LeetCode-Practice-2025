class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        } else {
            return 1 + max(maxDepth(root->left), maxDepth(root->right));
        }
    }
};

/*
maximum depth -> the farest node -> DFS
use recursion to achieve it
*/