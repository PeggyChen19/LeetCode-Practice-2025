class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (!root) return {};
        // 1. record parents
        unordered_map<TreeNode*, TreeNode*> parent;
        buildParent(root, nullptr, parent);
        // 2. Find kth nodes
        int dist = 0;
        vector<int> results;
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);
        while(true) {
            int size = q.size();
            for (int s = 0; s < size; s++) {
                TreeNode* cur = q.front();
                q.pop();
                if (dist == k) {
                    results.push_back(cur->val);
                } else {
                    if (cur->left && !visited.count(cur->left)) {
                        q.push(cur->left);
                        visited.insert(cur->left);
                    }
                    if (cur->right && !visited.count(cur->right)) {
                        q.push(cur->right);
                        visited.insert(cur->right);
                    }
                    if (parent[cur] && !visited.count(parent[cur])) {
                        q.push(parent[cur]);
                        visited.insert(parent[cur]);
                    }
                }
            }
            if (dist == k) break;
            dist++;
        }
        return results;
    }
private:
    void buildParent(TreeNode* child, TreeNode* parent, unordered_map<TreeNode*, TreeNode*>& p) {
        if (!child) return;
        p[child] = parent;
        buildParent(child->left, child, p);
        buildParent(child->right, child, p);
    }
};
/*
We need to go upward (to parent) in this problem -> record relationship node:parent
1. Traverse the tree & record parents
2. Start from target, use BFS (left, right, parent) to find all kth nodes
*/