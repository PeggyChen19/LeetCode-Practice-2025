class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int result = 0;
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
                if (node->left) q.push({node->left, ind * 2});
                if (node->right) q.push({node->right, ind * 2 + 1});
            }
            result = max(result, (int)(right - left + 1));
        }
        return result;
    }
};
/*
Max width: leftmost ~ rightmost, including null nodes
Define nodeInd = parentInd * 2 + (is right child)
When we trasfer the tree to 1D vector, nodeInd will be the vector ind
BFS: find the left most & right most of each layer
queue<pair<TreeNode*, int>> // node, index
    1
   / \
  2   3
 / \ / \
4  5 6  7
*/