class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode *fast = dummy, *slow = dummy;
        for (int i = 0; i < n; i++) { // fast goes n times
            fast = fast->next;
        }
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        // when fast->next == nullptr, slow->next = the last n
        slow->next = slow->next->next;
        return dummy->next;
    }
};
/*
Two pointer with n distance, when the fast one reaches the end, the slow one reaches the last n
Note: n <= list size
Example:
n = 2
d 1 2 3 4 5
^   ^ 
      ^   ^
*/