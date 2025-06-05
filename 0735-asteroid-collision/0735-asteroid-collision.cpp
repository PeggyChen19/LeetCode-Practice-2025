class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        for (auto& a : asteroids) {
            while (true) {
                int back = result.empty() ? 0 : result.back();
                if (back != 0 && back > 0 && a < 0) { // collision
                    if (back < -a) {
                        result.pop_back();
                    } else if (back == -a) {
                        result.pop_back();
                        break;
                    } else {
                        break; // ignore new a
                    }
                } else {
                    result.push_back(a);
                    break;
                }
            }
        }
        return result;
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