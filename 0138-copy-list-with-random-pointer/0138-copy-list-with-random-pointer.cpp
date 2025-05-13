/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        // Step 1: Create new nodes: A->A'->B->B'
        Node* cur = head;
        while (cur) {
            Node* copy = new Node(cur->val);
            copy->next = cur->next;
            cur->next = copy;
            cur = copy->next;
        }
        // Step 2: Assign random pointers
        cur = head;
        while (cur && cur->next) {
            if (cur->random) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        // Step 3: Separate the copied from the original
        Node* newHead = head->next;
        cur = head;
        while (cur && cur->next) {
            Node* originalNext = cur->next;
            cur->next = cur->next->next;
            cur = originalNext;
        }
        return newHead;
    }
};
/*
create a new linked list from head to end based on val & next
how about random? how can we know the relationship between old and new node?
brute force: use a vector to record the new node pointer in order

Improvement: Costant Space -> interweaving
1. Create new nodes: A->A'->B->B'
2. Assign random pointers (based on the relationship "orignal --next--> new")
   -> we can know the new random target based on original node
3. Separate the copied from the original
*/