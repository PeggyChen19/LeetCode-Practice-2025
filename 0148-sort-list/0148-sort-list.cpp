class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        // 1) length
        int n = 0;
        ListNode* p = head;
        while (p) {
            n++;
            p = p->next;
        }

        // 2) dummy head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // 3) bottom-up merge: block sizes 1,2,4,8,...
        for (int step = 1; step < n; step *= 2) {
            // start merge from head every time
            ListNode* prev = dummy;       // tail of sorted list
            ListNode* cur  = dummy->next; // head of unsorted list
            while (cur) {
                ListNode* left  = cur;               // left part
                ListNode* right = split(left, step); // right part, cut after 'step' nodes
                cur = split(right, step);            // next head of unsorted list
                prev = merge(left, right, prev);     // merge two parts and return new tail
            }
        }
        return dummy->next;
    }

private:
    // cut list after 'step' nodes; return head of the remainder.
    ListNode* split(ListNode* head, int step) {
            step--; // head is the first node
        while (step && head) { // go (step - 1) steps
            head = head->next;
            step--;
        }
        if (!head) {
            return nullptr; // nothing in second part
        }
        ListNode* second = head->next; // set up the second part
        head->next = nullptr; // split the two parts
        return second;
    }

    // merge l1 and l2, appending after 'tail'. Return the new tail (end of merged).
        ListNode* merge(ListNode* l1, ListNode* l2, ListNode* tail) {
        ListNode* cur = tail; // start to connect the newly sorted nodes
        while (l1 && l2) {
            if (l1->val <= l2->val) { 
                cur->next = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        while (cur->next) { // go to the tail of sorted list
            cur = cur->next;
        }
        return cur;
    }
};