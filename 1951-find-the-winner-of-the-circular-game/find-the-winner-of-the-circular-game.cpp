class Solution {
public:
    // Returns winner's index among n players with every k-th player removed
    int findTheWinner(int n, int k) { return f(n, k) + 1; }

private:
    // Recursively finds winner after removing k-th player in each round
    int f(int n, int k) {
        if (n == 1)
            return 0; // Index of the last player remaining
        return (f(n - 1, k) + k) % n; // Next player's index after removal
    }
};
