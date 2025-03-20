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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string root_str = tree2str(root, "");
        string sub_str = tree2str(subRoot, "");
        if (root_str.find(sub_str) != string::npos) {
            return true;
        } else {
            return false;
        }
    }

private:
    string tree2str(TreeNode* node, string s) {
        if (node) {
            s = s + "," + to_string(node->val);
        } else {
            s += ",N";
            return s;
        }
        return tree2str(node->right, (tree2str(node->left, s)) );
    }
};