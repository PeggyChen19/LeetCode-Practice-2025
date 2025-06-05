class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        for (auto& item : asteroids) {
            handleNewItem(result, item);
        }
        return result;
    }
private:
    void handleNewItem(vector<int>& result, int item) {
        int back = result.empty() ? 0 : result.back();
        if (back != 0 && back > 0 && item < 0) { // collision
            if (back < -item) {
                result.pop_back();
                handleNewItem(result, item);
            } else if (back == -item) {
                result.pop_back();
            }
            // else if (back > -item) -> ignore new item
        } else {
            result.push_back(item);
        }
    }
};
/*
10 -8 5 3 -7
10 5 3 -7
10 5 -7
10 -7
10
We can use stack to simulate the collision
if stack.top() > 0 & incoming asteroid < 0 -> collision
else -> push into the stack
Because the return type is vector, use vector represent stack
*/