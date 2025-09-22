class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> newPeople(n + 1, 0);
        newPeople[1] = 1;
        int validWindow = 0;
        int MOD = 1000000007;
        for (int i = 2; i <= n; i++) {
            if (i - forget >= 0) {
                validWindow = (validWindow - newPeople[i - forget] + MOD) % MOD;
            }
            if (i - delay  >= 0) {
                validWindow = (validWindow + newPeople[i - delay]) % MOD;
            }
            newPeople[i] = validWindow;
        }
        int result = 0;
        for (int i = n - forget + 1; i <= n; i++) {
            result = (result + newPeople[i]) % MOD;
        }
        return result;
    }
};
/*
vector<int> newPeople(n + 1, 0)
newPeople[1] = 1
int valid = 0 // the people who not yet forget the secret and pass the delay days

for loop to go through each day i
    valid -= newPeople[i - forget] // check if the index is valid, if not, don't update 
    valid += newPeople[i - delay] // check if the index is valid, if not, don't update 
    newPeople[i] = sum(newPeople[i - forget + 1, i - delay]) = valid
return sum(newPeople[n - forget + 1, n])

a b c [window] d e f
a b c x [window] e f

the last day the oldest people on day a can share the secret, i = a + forget - 1
the first day the newset people on day b can share the secret i = b + delay, b = i - delay

n = 8, delay = 2, forget = 4
index     1 2 3 4 5 6 7 8
newPeople 1   d   f
*/