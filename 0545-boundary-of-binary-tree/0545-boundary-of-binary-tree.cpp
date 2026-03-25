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
 
void dfsLeft(TreeNode* root, vector<int>&result){
    if(!root) return;
    if(!root->left && !root->right) return; // leaf

    result.push_back(root->val);
    if(root->left) dfsLeft(root->left, result);
    else dfsLeft(root->right, result);
}

void dfsBottom(TreeNode* root, vector<int>& result){
    if(!root) return;
    if(!root->left && !root->right){
        result.push_back(root->val);
        return;
    }

    dfsBottom(root->left, result);
    dfsBottom(root->right, result);
}

void dfsRight(TreeNode* root, vector<int>& result){
    if(!root) return;
    if(!root->left && !root->right) return;

    if(root->right) dfsRight(root->right, result);
    else dfsRight(root->left, result);
    result.push_back(root->val);
}

class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(!root) return {};
        if(!root->left && !root->right) return {root->val};

        vector<int>result;
        result.push_back(root->val);
        dfsLeft(root->left, result);
        dfsBottom(root, result);
        dfsRight(root->right, result);

        return result;
    }
};