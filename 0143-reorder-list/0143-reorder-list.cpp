class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head) return;
        // find the middle node (slow)
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // reverse the second part
        ListNode* pre = nullptr;
        ListNode* cur = slow->next;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        // combine
        ListNode* first = head;
        ListNode* second = pre;
        while (first && second) {
            ListNode* firstNext = first->next;
            ListNode* secondNext = second->next;
            first->next= second;
            second->next = firstNext;
            first = firstNext;
            second = secondNext;
        }
        first->next = nullptr;
    }
};
/*
1. find the middle
2. reverse the second part
3. combine
*/