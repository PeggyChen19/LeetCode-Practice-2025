class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> primes(n, true);
        primes[0] = false;
        primes[1] = false;
        for (int i = 0; i * i < n; i++) { // go through all nums
            if (primes[i]) {
                for (int multiple = i * i; multiple < n; multiple += i) {
                    primes[multiple] = false;
                }
            }
        }
        int count = 0;
        for (bool prime : primes) {
            if (prime) count++;
        }
        return count;
    }
};
/*
if n < 2: return 0
create bool vector, mark all nums to be true (will mark them as false via multiplying primes later)
mark 0, 1 as false
iterate i from 1 to n
    if prime[i] = true
        // i * 0 ~ i * (i - 1) have handled by other smaller prime
        iterate multiple from i * i to n, multiple += i
            prime[multiple] = false
calculate prime counts

optimal (optional): skip even nums
*/