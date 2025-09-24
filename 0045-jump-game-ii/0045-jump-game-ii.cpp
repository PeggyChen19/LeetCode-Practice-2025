class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int step = 0, curReachable = 0, nextReachable = 0;
        for (int i = 0; i < nums.size(); i++) {
            nextReachable = max(nextReachable, i + nums[i]);
            if (i == curReachable) {
                curReachable = nextReachable;
                step++;
            }
            if (curReachable >= nums.size() - 1) return step;
        }
        return -1;
    }
};
/*
DP -> hard to write the transition function

Greedy -> record and update the "current max reachable"
we also need to record the steps needed for the reachable range
however, when we go through within the range, we will have to extend the reachable range
how to update the steps correctly?
two reachable: curReachable(with steps) & nextReachable(the potential within the curReachable)
curReachable = nextReachable = step = 0
for i = 0; i < size; i++
    update nextReachable with max(nextReachalbe, i + nums[i])
    when i == curReachable
        curReachable = nextReachable
        step++
*/