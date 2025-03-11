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
        ListNode dummyHead;
        ListNode* newCur = &dummyHead;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                newCur->next = list1;
                list1 = list1->next;
            } else {
                newCur->next = list2;
                list2 = list2->next;
            }
            newCur = newCur->next;
        }
        if (list1) {
            newCur->next = list1;
        } else if (list2) {
            newCur->next = list2;
        }
        return dummyHead.next;
    }
};