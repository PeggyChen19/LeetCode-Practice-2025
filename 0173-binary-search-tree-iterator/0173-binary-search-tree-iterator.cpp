class BSTIterator {
public:
    stack<TreeNode*> path;

    BSTIterator(TreeNode* root) {
        findLeftMost(root);
    }
    
    int next() {
        TreeNode* node = path.top();
        path.pop();
        if (node->right) { // go right once and keep exploring left
            findLeftMost(node->right);
        }
        return node->val;
    }
    
    bool hasNext() {
        return !path.empty();
    }

private:
    void findLeftMost(TreeNode* node) {
        while (node) {
            path.push(node);
            node = node->left;
        }
    }
};
/*
members: path stack 

init: find the left most node and record the path
next: in-order: left -> root -> right
top is the next, try to explore the left most node from top->right
*/