// dynamic program..

vector<int> dp(46, -1);
class Solution {
public:
    int climbStairs(int n) {

        // if result for n is already computed, return it.
        if (dp[n] != -1)
            return dp[n];

        if (n <= 2) {
            return dp[n] = n;
        }

        // recursively compute & store result for n using results for n-1 & n-2
        return dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
    }
};
