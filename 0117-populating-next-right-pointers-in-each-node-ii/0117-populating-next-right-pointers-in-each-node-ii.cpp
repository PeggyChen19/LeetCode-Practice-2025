class Solution {
public:
    Node* connect(Node* root) {
        Node* cur = root;
        while (cur) { // the whole tree
            Node* dummy = new Node();
            Node* lowerCur = dummy;
            while (cur) { // each layer
                if (cur->left) {
                    lowerCur->next = cur->left;
                    lowerCur = lowerCur->next;
                }
                if (cur->right) {
                    lowerCur->next = cur->right;
                    lowerCur = lowerCur->next;
                }
                cur = cur->next;
            }
            cur = dummy->next; // start from the lower layer
        }
        return root;
    }
};
/*
BFS: use queue to handle each layer by order
Follow-up: constant space
Improved BFS method: utilize the next pointer to replace queue
start from layer head -> set up next pointer for lower layer -> iterate the layer using "next" 
-> start from lower layer head (use dummy node)
*/