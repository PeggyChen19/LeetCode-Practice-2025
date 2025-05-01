class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 1. find the meeting point
        int slow = nums[0];
        int fast = nums[nums[0]];
        while (slow != fast) {
            slow = nums[slow]; // 1 step
            fast = nums[nums[fast]]; // 2 steps
        }
        // 2. find the cycle head
        int head = 0;
        int meet = slow;
        while (head != meet) {
            head = nums[head];
            meet = nums[meet];
        }
        return meet;
    }
};
/*
ind  0 1 2 3 4
node 1 3 4 2 2 

0 -> 1 -> 3 -> 2 -> 4
               ^----|

range: 1~n, size: n+1 (index: 0~n)
關鍵：把這個 vector 視為 "linked list"
每個 index 上的 element 都是一個 node，element 的 value 就是指向下一個 node 的 index
當有兩個 element 有同樣的 value，這個 linked list 就會跑回已經去過的 node -> 形成 cycle

two pointers: 
1. find meet point use fast(go 2 steps) & slow(go 1 step)
2. use meet point to find the head of the cycle -> how?

head ---s--- cycle --- x --- meet
               ^---- c-x -----|
s+nc+x = 2(s+x)
s+x = nc (nc = c because cycle goes back to the same place)
s = c-x
two pointers with same speed from head & meet respecitvely
the meeting point is the cycle head
*/