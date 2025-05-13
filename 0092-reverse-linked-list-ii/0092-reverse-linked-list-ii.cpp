class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) { // not need reverse
            return head;
        }
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* pre = dummy;
        for (int i = 1; i < left; i++) { // cur will stop at left-1
            pre = pre->next;
        }
        ListNode* cur = pre->next;
        for (int i = 0; i < (right - left); i++) {
            ListNode* rangeHead = cur->next;
            cur->next = rangeHead->next;
            rangeHead->next = pre->next;
            pre->next = rangeHead;
        }
        return dummy->next;
    }
};
/*
直接用原本的 reverse 會變得很複雜 -> Head Insertion
Head Insertion: reverse a sublist in a linked list
1. Find Pointers
    a. pre: the node before the sublist
    b. cur: the first node in the sublist
2. Repeat right - left times:
    a. find the future new head of the sublist: rangeHead = cur->next
    b. detach rangeHead: cur->next = rangeHead->next: 
    c. insert rangeHead right after pre:
        rangeHead->next = pre->next
        pre->next = rangeHead    
*/