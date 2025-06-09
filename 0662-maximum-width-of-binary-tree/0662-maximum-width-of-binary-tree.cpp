class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int result = 0;
        if (!root) return result;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 1});
        while (!q.empty()) {
            int size = q.size();
            unsigned long long left, right;
            for (int i = 0; i < size; i++) {
                auto [node, ind] = q.front();
                q.pop();
                if (i == 0) left = ind;
                if (i == size - 1) right = ind;
                if (node->left) q.push({node->left, ind * 2 - 1});
                if (node->right) q.push({node->right, ind * 2});
            }
            result = max(result, (int)(right - left + 1));
        }
        return result;
    }
};
/*
Max width: leftmost ~ rightmost, including null nodes
Define nodeInd = parentInd * 2 - (is left child)
BFS: find the left most & right most of each layer
queue<TreeNode*, int> // node, index
        1
       / \
      1   2
     / \ / \
    1  2 3  4
*/