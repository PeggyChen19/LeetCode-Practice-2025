class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
/*
use two pointers: slow (1 step) and fast (2 steps)
when fast reaches the end, slow only goes half of the whole length
fast: 1 3
slow: 1 2
if 3 == nullptr (1 2) -> return 2
if 4 == nullptr (1 2 3) -> return 2
*/