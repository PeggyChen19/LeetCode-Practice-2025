/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) {
            return head;
        }
        ListNode dummyHead(0, head);
        ListNode* left = &dummyHead;
        ListNode* right = &dummyHead;
        for (int i = 0; i < n; i++) {
            right = right->next;
        }
        while (right->next) {
            left = left->next;
            right = right->next;
        }
        left->next = left->next->next;
        return dummyHead.next;
    }
};
/*
node_size >= 1
1 <= n <= node_size
x 0 1 2 3 4
s   f
      s   f
n = 2, remove "3"
*/