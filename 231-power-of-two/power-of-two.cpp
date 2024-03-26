// BIT MAGIC
class Solution {
public:
    bool isPowerOfTwo(int n) {
        // Check if n is positive and has only one bit set
        return n > 0 && (n & (n - 1)) == 0;
    }
};

// // ITERATIVE
// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         if (n == 1)
//             return true; // Base case: n equals 1

//         if (n < 1 || n % 2 != 0)
//             return false; // n less than 1 or odd

//         // Iterative: divide n by 2 until it's not divisible
//         while (n > 1) {
//             if (n % 2 != 0)
//                 return false;
//             n /= 2;
//         }
//         return true;
//     }
// };

// // RECURSIVE
// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//
//         if (n == 1)
//             return true; // Base case: n equals 1
//
//         if (n < 1 || n % 2 != 0)
//             return false;  // n less than 1 or odd
//
//         return isPowerOfTwo(n / 2); // Recursive: divide n by 2
//     }
// };