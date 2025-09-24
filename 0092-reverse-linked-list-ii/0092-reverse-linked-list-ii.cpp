class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* leftPre = dummyHead;
        ListNode* cur = head;
        for (int i = 1; i < left; i++) {
            leftPre = cur;
            cur = cur->next;
        }
        ListNode* leftStart = cur;
        ListNode* pre = nullptr;
        for (int i = 0; i < right - left + 1; i++) { // reverse right - left + 1 times
            ListNode* realNext = cur->next;
            cur->next = pre;
            pre = cur;
            cur = realNext;
        }
        // cur is rightNext
        // pre is right
        leftPre->next = pre;
        leftStart->next = cur;
        return dummyHead->next;
    }
};
/*
l = 2, r = 4
1 [2 3 4] 5 
^  l   r  ^
leftPre   rightNext
1 [4 3 2] 5

1. find the left, record leftPre
2. reverse internal until right, record rightNext
3. leftPre->next = right, left->next = rightNext
*/