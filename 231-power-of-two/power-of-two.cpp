class Solution {
public:
    bool isPowerOfTwo(int n) {
        // Base case: if n becomes 1, it means it was a power of two
        if (n == 1)
            return true;

        // If n becomes less than 1 or odd, it can't be a power of two
        if (n < 1 || n % 2 != 0)
            return false;

        // Recursive case: continue dividing n by 2
        return isPowerOfTwo(n / 2);
    }
};