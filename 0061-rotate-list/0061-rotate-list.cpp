class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        int size = 0;
        ListNode* cur = head;
        while (cur) { // get the size of linked list
            cur = cur->next;
            size++;
        }
        k %= size; // get the real rotate counts
        if (k == 0) return head; // no rotation
        ListNode* left = head;
        ListNode* right = head;
        for (int i = 0; i < k; i++) { // move right k steps before left
            right = right->next;
        }
        while (right->next) { // right stops at the end of the list
            left = left->next;
            right = right->next;
        }
        ListNode* newHead = left->next;
        left->next = nullptr; // left is the new end
        right->next = head; // old end connect to old head
        return newHead;
    }
};
/*
1 2 3 4 5
    l   r
5 1 2 3 4 rotate 1
4 5 1 2 3 rotate 2
rotate k times -> move the last k element to the head
how to find the last k element -> two poiners (distance k)
mod k with size first
*/