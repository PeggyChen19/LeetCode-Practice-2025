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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            int l1_val = l1 ? l1->val : 0;
            int l2_val = l2 ? l2->val : 0;
            int ans = l1_val + l2_val + carry;
            carry = ans / 10;
            cur->next = new ListNode(ans % 10);
            cur = cur->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return dummy->next;
    }
};
/*
1 10 100
1 2  9
1 8

 921
  81
----
1002
do the add operation from the lowest digit
notice! check if l1 / l2 is null or not
use carry if we need to carry 1 to the next digit
*/