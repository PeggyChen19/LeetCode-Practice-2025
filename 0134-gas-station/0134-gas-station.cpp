class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum_diff = 0, tank = 0, start = 0;
        for (int i = 0; i < gas.size(); i++) {
            int diff = gas[i] - cost[i];
            sum_diff += diff;
            tank += diff;
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }
        return (sum_diff >= 0) ? start : -1;
    }
};
/*
        0 1 2 3 4
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]
Output: 3
The problem ensures that the answer is unique

For each station, the tank adds "gas" and reduces "cost" to go to next station
The tank should always >= 0
diff: gas - cost
 0  1  2  3  4
-2 -2 -2  3  3

Greedy: 
Set index 0 as start point
Go through all stations 
    calculate global_sum_diff
    calculate tank_sum from start point
    if tank_sum < 0
        start = i+1 // because start~i cannot be the possible answer
        tank_sum = 0
if global_sum_diff < 0 -> no answer

當從 start~i 的 tank 小於 0，代表說這段區間整體來說只會是負的影響，所以直接整段捨棄，從 i+1 開始
第一直覺會覺得或許可以從 start+1 開始，但這樣其實只可能虧更多（start 不一定是虧的，是繼續往後走之後才開始虧）
所以才可以直接整段捨棄
*/