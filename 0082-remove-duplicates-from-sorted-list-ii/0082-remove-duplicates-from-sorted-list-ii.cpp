class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        bool duplicated = false;
        ListNode* dummyHead = new ListNode();
        ListNode* preValid = dummyHead;
        ListNode* cur = head;
        while (cur) {
            if (cur->next && cur->val == cur->next->val) {
                duplicated = true;
            } else {
                if (!duplicated) {
                    preValid->next = cur;
                    preValid = cur;
                }
                duplicated = false;
            }
            cur = cur->next;
        }
        preValid->next = nullptr;
        return dummyHead->next;
    }
};
/*
1 1 2 3 3 4
create bool duplicated
create ListNode* cur, preValid
use cur iterate the linked list
if cur is duplicated: skip it and go to next val
else: preValid->next = cur
*/