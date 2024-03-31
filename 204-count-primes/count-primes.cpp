// Sieve of Eratosthenes
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n, true);

        for (int i = 2; i * i < n; i++) {
            if (prime[i]) {
                for (int j = i * i; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }

        int ans = 0;
        for (int i = 2; i < n; i++) {
            if (prime[i])
                ans++;
        }
        return ans;
    }
};

// // NAIVE SOLUTION
// class Solution {
// public:
//     int countPrimes(int n) {
//         int count = 0;
//         for (int i = 2; i < n; i++) {
//             if (isPrime(i)) {
//                 count++;
//             }
//         }
//         return count;
//     }
// private:
//     bool isPrime(int num) {
//         if (num <= 1)
//             return false;
//         for (int i = 2; i * i <= num; i++) {
//             if (num % i == 0) {
//                 return false;
//             }
//         }
//         return true;
//     }
// };
