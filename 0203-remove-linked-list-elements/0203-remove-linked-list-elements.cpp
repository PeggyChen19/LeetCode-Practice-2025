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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return head;
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* prev = dummyHead;
        ListNode* curr = head;
        while (curr) {
            if (curr->val == val) {
                ListNode* tmp = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete(tmp);
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return dummyHead->next;
    }
};
/*
create dummyHead (avoid error when removing head)
record prev, curr, next
when curr == val, connect prev & next
move curr pointer to next
*/