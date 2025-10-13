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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                minHeap.push({lists[i]->val, i});
            }
        }
        ListNode* dummyHead = new ListNode(0);
        ListNode* cur = dummyHead;
        while (!minHeap.empty()) {
            auto [val, ind] = minHeap.top();
            minHeap.pop();
            cur->next = lists[ind];
            cur = cur->next;
            lists[ind] = lists[ind]->next;
            if (lists[ind]) {
                minHeap.push({lists[ind]->val, ind});
            }
        }
        return dummyHead->next;
    }
};
/*
priority_queue<pair<int, int>> minHeap // node val, list index
push all first elements of each list into heap
set up dummyHead
cur = dummyHead
while heap is not empty
    get the top: {smallest val, list index}
    cur->next = top
    cur = cur->next
    move the list index pointer forward
    push the list index pointer into heap
*/