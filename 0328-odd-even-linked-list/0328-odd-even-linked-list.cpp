class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head; // 0 or 1 node
        ListNode* oddCur = head;
        ListNode* evenHead = head->next;
        ListNode* evenCur = evenHead;
        while (evenCur) {
            oddCur->next = evenCur->next;
            oddCur = evenCur->next;
            if (!oddCur) break;
            evenCur->next = oddCur->next;
            evenCur = oddCur->next;
        }
        oddCur->next = evenHead;
        return head;
    }
};
/*
odd -> even
1 2 3 4
Create some pointers: oddCur, evenCur, evenHead
oddCur = head
evenHead = evenCur = head->next
while evenCur
    oddCur->next = evenCur->next
    oddCur = evenCur->next
    if (!oddCur) break
    evenCur->next = oddCur->next
    evenCur = oddCur->next
oddCur->next = evenHead

Time: O(n)
Space: O(1)
*/