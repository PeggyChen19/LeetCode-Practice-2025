class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummyLeftHead = new ListNode(), *dummyRightHead = new ListNode();
        ListNode *curLeft = nullptr, *curRight = nullptr;
        while (head) {
            if (head->val < x) {
                if (!curLeft) { // set up head
                    curLeft = head;
                    dummyLeftHead->next = curLeft;
                } else {
                    curLeft->next = head;
                    curLeft = curLeft->next;
                }
            } else {
                if (!curRight) { // set up head
                    curRight = head;
                    dummyRightHead->next = curRight;
                } else {
                    curRight->next = head;
                    curRight = curRight->next;
                }
            }
            head = head->next;
        }
        if (!curLeft) return dummyRightHead->next; // only right part
        curLeft->next = dummyRightHead->next; // link two lists
        if (curRight) curRight->next = nullptr; // end in right part
        return dummyLeftHead->next;
    }
};
/*
ListNode pointers: dummyLeftHead, dummyRightHead, cur(head), curLeft, curRight
Maintain these pointers
*/