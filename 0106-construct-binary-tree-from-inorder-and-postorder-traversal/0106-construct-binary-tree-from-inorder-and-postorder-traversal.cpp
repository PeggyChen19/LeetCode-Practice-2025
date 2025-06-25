class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < n; i++) {
            inorderMap[inorder[i]] = i;
        }
        return helper(inorderMap, postorder, 0, n - 1, 0, n - 1);
    }
private:
    TreeNode* helper(unordered_map<int, int>& inorderMap, vector<int>& postorder, int inLeft, int inRight, int postLeft, int postRight) {
        if (postLeft > postRight) return nullptr;
        int rootVal = postorder[postRight];
        TreeNode* root = new TreeNode(rootVal);
        int rootInd = inorderMap[rootVal];
        int leftCount = rootInd - inLeft;
        root->left = helper(inorderMap, postorder, inLeft, rootInd - 1, postLeft, postLeft + leftCount - 1);
        root->right = helper(inorderMap, postorder, rootInd + 1, inRight, postLeft + leftCount, postRight - 1);
        return root;
    }
};
/*
inorder: left, root, right
postorder: left, right, root

1. find the root (the last element of postorder)
2. find the the number of nodes of left and right subtrees via inorder
3. for left part, repeate 1, 2
4. for right part, repeate 1, 2
for quick lookup from inorder -> use unordered_map<int, int>: val, ind
*/