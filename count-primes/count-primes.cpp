// Using Sieve of Eratosthenes
// Time Complexity: O(sqrt(N)loglogN)
// Space Complexity: O(N)
class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        vector<int> primes(n, 0);
        int count = 0;
        for(int i = 2; i <= sqrt(n); i++) {
            if(primes[i] == 0) {
                for(int j = i*i; j < n; j += i)
                    primes[j] = 1;
            }
        }
        for(int i = 2; i < n; i++) {
            if(primes[i] == 0)
                count++;
        }
        return count;
    }
};