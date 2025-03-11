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
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        ListNode* dummyHead = new ListNode();
        ListNode* newCur = dummyHead;
        while (cur1 != NULL || cur2 != NULL) {
            if (cur1 == NULL || (cur2 != NULL && cur2->val < cur1->val)) {
                newCur->next = cur2;
                cur2 = cur2->next;
            } else {
                newCur->next = cur1;
                cur1 = cur1->next;
            } 
            newCur = newCur->next;
        }
        return dummyHead->next;
    }
};