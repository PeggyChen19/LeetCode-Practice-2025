class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head; // 0 or 1 node
        ListNode* oddCur = head;
        ListNode* evenHead = head->next;
        ListNode* evenCur = evenHead;
        ListNode* cur = evenHead->next;
        while (cur) {
            oddCur->next = cur;
            oddCur = cur;
            cur = cur->next;
            evenCur->next = cur;
            evenCur = cur;
            if (!cur) break;
            cur = cur->next;
        }
        oddCur->next = evenHead;
        return head;
    }
};
/*
odd -> even
1 2 3 4 5
Create some pointers: oddCur, evenCur, cur
oddCur = head
evenCur = head->next (nullptr check)
cur = head->next->next
while cur
    oddCur->next = cur
    oddCur = cur
    cur = cur->next (nullptr check)
    evenCur->next = cur
    evenCur = cur
    cur = cur->next

Time: O(n)
Space: O(1)
*/