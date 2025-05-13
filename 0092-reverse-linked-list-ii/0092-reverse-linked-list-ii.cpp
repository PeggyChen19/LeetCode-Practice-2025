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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) { // don't need reverse
            return head;
        }
        ListNode* cur = head;
        for (int i = 2; i < left; i++) { // cur will stop at left-1
            cur = cur->next;
        }
        ListNode* left_end = cur;
        cur = cur->next;
        ListNode* pre = nullptr;
        for (int i = 0; i < (right-left+1); i++) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        left_end->next->next = cur; // cur is right_start
        left_end->next = pre; // pre is right
        return head;
    }
};