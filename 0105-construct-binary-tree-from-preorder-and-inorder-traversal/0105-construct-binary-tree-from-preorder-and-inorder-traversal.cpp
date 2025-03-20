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
private:
    unordered_map<int, int> inorder_map;
    int preorder_ind = 0;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) { // initialize map
            inorder_map[inorder[i]] = i;
        }
        return buildSubTree(preorder, 0, preorder.size() - 1);
    }
    TreeNode* buildSubTree(vector<int>& preorder, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        int root_value = preorder[preorder_ind];
        int inorder_ind = inorder_map[root_value];
        TreeNode* root = new TreeNode(root_value);
        preorder_ind++;
        root->left = buildSubTree(preorder, start, inorder_ind - 1);
        root->right = buildSubTree(preorder, inorder_ind + 1, end);
        return root;
    }
};
/*
preorder: root left right
inorder:  left root right
1. use preorder to get the root
2. the elements before root in inorder belong to left subtree
    a. in preorder, the value next to the root is the root of left subtree
3. the elements after root in inorder belong to right subtree
    a. in preorder, the first value of the right subtree is the root of right subtree
----
we need to find the seperator in inorder quickly -> use hash map to record value:index
we will go through the preorder one by one because this is the root order, 
and then we use inorder to know left or right node

     1
    / \
   2   3
  / \   \
 4   5   6
preorder: 1 2 4 5 3 6
inorder:  4 2 5 1 3 6
*/