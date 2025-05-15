class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int size = position.size();
        vector<pair<int, double>> cars(size); // position, time
        for (int i = 0; i < size; i++) {
            cars[i] = {position[i], ((double)(target - position[i]) / speed[i])};
        }
        sort(cars.rbegin(), cars.rend()); // big -> small
        int fleet = 0;
        double maxTime = 0;
        for (auto& car : cars) {
            if (car.second > maxTime) { // not meet next car
                fleet++;
                maxTime = car.second;
            }
        }
        return fleet;
    }
};
/*
Rule & Limit:
1. Cannot pass another car
   Insight: A car can only join a fleet of next car/cars -> sort the car based on position
2. Catch up -> join fleet and sync speed (min)
   Insight: Keep tracking the min speed of fleet -> Max time needed to go to target
3. Cars stop at target
   Insight: Only consider 0~target miles -> 不需要模擬移動，只需要知道是否在抵達前追上
4. Become a fleet at target is considered a fleet
   Insight: For cars with same time -> become fleet

Step 1:
Calcuate time needed to go to target
Step 2:
Sort the cars based on position (big to small)
Step 3:
maxTime = 0
For all cars
    if car.time > maxTime // not meet next car
        maxTime = car.time
        fleet++
*/