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
        if (head == nullptr) {
            return head;
        }
        // Step 1: Create new node just behind the original node
        Node* cur = head;
        while (cur) {
            Node* newNode = new Node(cur->val);
            Node* oldNext = cur->next;
            cur->next = newNode;
            newNode->next = oldNext;
            cur = oldNext;
        }
        Node* dummyNewHead = new Node(0);
        dummyNewHead->next = head->next; // real head of new linked list
        // Step 2: Set up new random pointers
        cur = head;
        while (cur && cur->next) {
            if (cur->random) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        // Step 3: Extract new nodes to be an independent linked list
        cur = head;
        while (cur && cur->next) {
            Node* originalNext = cur->next;
            cur->next = cur->next->next;
            cur = originalNext;
        }
        return dummyNewHead->next;
    }
};
/*
create a new linked list from head to end based on val & next
how about random? how can we know the relationship between old and new node?
brute force: use a vector to record the new node pointer in order

Improvement: Costant Space -> interweaving
1. Create new node just behind the original node
   A -> A' -> B -> B' -> C -> C'
2. Set up new random pointers (based on the relationship "orignal --next-->
new")
   -> we can know the new random target based on original node
3. Extract new nodes to be an independent linked list
*/