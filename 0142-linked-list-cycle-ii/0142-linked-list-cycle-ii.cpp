/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) break;
        }
        if (fast != slow) return nullptr; // no cycle
        ListNode* meet = fast;
        while (head != meet) {
            head = head->next;
            meet = meet->next;
        }
        return meet;
    }
};
/*
fast (go 2 steps) & slow (go 1 step) pointers
if has cycle -> fast == slow
else -> fast reaches nullptr

head----L----cycleHead----x-----meet
                ^------(c-x)-----|
2(L+x) = L + nc + x
L + x = nc
L = nc - x
L = c - x

set two pointer start from head & meet respectively
when they met again, that's the cycle head
*/