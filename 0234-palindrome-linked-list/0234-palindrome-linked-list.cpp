class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return head; // 0 or 1 node
        // find the middle point
        ListNode *slow = head, *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // reverse the right part
        ListNode* pre = nullptr;
        ListNode* cur = slow;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        // Compare two parts
        while (pre && head) {
            if (pre->val != head->val) return false;
            pre = pre->next;
            head = head->next;
        }
        return true;
    }
};
/*
Time: O(n), Space: O(1)
1. Find the middle using slow-fast pointers
2. Reverse the right part
3. Compare two parts
*/