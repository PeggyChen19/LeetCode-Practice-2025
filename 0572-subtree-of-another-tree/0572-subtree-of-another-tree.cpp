class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string sRoot, sSub;
        tree2str(root, sRoot);
        tree2str(subRoot, sSub);
        if (sRoot.find(sSub) != string::npos) {
            return true;
        } else {
            return false;
        }
    }

private:
    void tree2str(TreeNode* node, string& s) {
        if (node) {
            s += "," + to_string(node->val);
        } else {
            s += ",N";
            return;
        }
        tree2str(node->left, s);
        tree2str(node->right, s);
    }
};