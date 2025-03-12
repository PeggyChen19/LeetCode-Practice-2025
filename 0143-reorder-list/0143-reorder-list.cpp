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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) { // return the list which doesn't need change
            return;
        }
        // 1. find the middle (or left of the middle) point
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 2. reverse the right part
        ListNode* right = slow->next; // the start of the right part
        slow->next = nullptr; // cut the original left part (important!!!)
        ListNode* pre = nullptr;
        while (right) {
            ListNode* next = right->next;
            right->next = pre;
            pre = right;
            right = next;
        }
        // 3. combine the two parts
        ListNode* left = head;
        right = pre;
        while (right) {
            ListNode* next_left = left->next;
            ListNode* next_right = right->next;
            left->next = right;
            right->next = next_left;
            left = next_left;
            right = next_right;    
        }
    }
};
/*
number of ListNodes: at least one
1 2 3 4
1 4 2 3
-
1 2 3 4 5
1 5 2 4 3
-
暴力解是開 vector 紀錄指標，但更好的狀況應該是空間複雜度 O(1)
去解析這個問題，會發現要做的是三件事：「找到中間點」&「後半段反轉」&「前半跟後半反轉合併，先放前再放後」
這三件事我們都有學過要怎麼做
1. 找到中間點：用快慢指針
2. 反轉：紀錄 pre cur next
3. 合併：用分離雙指針
*/