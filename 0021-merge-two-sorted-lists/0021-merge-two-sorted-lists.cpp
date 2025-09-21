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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyHead = new ListNode();
        ListNode* curNew = dummyHead;
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        while (cur1 && cur2) {
            if (cur1->val < cur2->val) { // choose cur1 (smaller one) and move forward
                curNew->next = cur1;
                cur1 = cur1->next;
            } else {
                curNew->next = cur2;
                cur2 = cur2->next;
            }
            curNew = curNew->next; // move new list forward
        }
        if (cur1) { // cur2 is finished but cur1 is not, so connect the remaining cur1 to new list
            curNew->next = cur1;
        } else if (cur2) {
            curNew->next = cur2;
        }
        return dummyHead->next;
    }
};
/*
curNew = dummyHead
cur1 = list1->head;
cur2 = list2->head;
while (cur1 && cur2)
    compare cur1 and cur2
    curNew->next = the smaller one
    move the smaller pointer forward
finish the remaining of list1 or 2 if exists
*/