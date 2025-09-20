// the smallest prime: 2

class Solution {
public:
    int countPrimes(int n) {
        int ans = 0;
        vector<bool> isPrime(n + 1, true);
        for(int i = 2; i < n; i++){
            if(isPrime[i] == true){
                ans++;
                int cur = i;
                while((long)cur * i < (long)n){ 
                    isPrime[cur * i] = false;
                    cur++;
                }
            }
            else continue;
        }
        return ans;
    }
};