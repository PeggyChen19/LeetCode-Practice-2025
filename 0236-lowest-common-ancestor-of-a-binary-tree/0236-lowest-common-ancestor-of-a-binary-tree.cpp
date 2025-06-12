class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        if (root ==  p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right) return root; // find the LCA
        return left ? left : right; // return the subtree which found p or q
    }
};
/*
Recursive DFS
Return type: TreeNode*
if (!cur)
    return nullptr
if (cur == p || cur == q) 
    return cur
left = LCA(root->left, p, q)
right = LCA(root->right, p, q) 
if (left && right): return cur // find the LCA
else if left: return left
else if right: return right
*/