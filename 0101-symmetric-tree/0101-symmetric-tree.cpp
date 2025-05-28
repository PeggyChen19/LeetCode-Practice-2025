class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return traverse(root->left, root->right);
    }
private:
    bool traverse(TreeNode* l, TreeNode* r) {
        if (!l && !r) return true;
        if (!l || !r || l->val != r->val) return false;
        return traverse(l->right, r->left) && traverse(l->left, r->right);
    }
};
/*
Recursive traverse
bool traverse(l, r)
    if (l->val != r->val) return false
    return traverse(l->right, r->left) && traverse(l->left, r->right)
*/