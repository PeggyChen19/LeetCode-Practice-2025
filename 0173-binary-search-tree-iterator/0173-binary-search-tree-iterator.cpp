class BSTIterator {
public:
    TreeNode* pointer;
    vector<TreeNode*> path;

    BSTIterator(TreeNode* root) {
        pointer = root;
        findLeftMost();
        path.push_back(pointer);
        pointer = nullptr;
    }
    
    int next() {
        if (pointer && pointer->right) { // go right once and keep exploring left
            pointer = pointer->right;
            findLeftMost();
        } else {
            pointer = path.back();
            path.pop_back();
        }
        return pointer->val;
    }
    
    bool hasNext() {
        if (pointer && pointer->right) {
            return true;
        } else {
            return !path.empty();
        }
    }

private:
    void findLeftMost() {
        while (pointer->left) {
            path.push_back(pointer);
            pointer = pointer->left;
        }
    }
};
/*
    5
   / \
  3   6
 / \   \
1  4    7
 \
  2
members: pointer, path vector

init: find the left most element and record the path
next: in-order: left -> root -> right
if cur->right: go right once and keep exploring left
else: go up until meeting an unvisited parent
*/