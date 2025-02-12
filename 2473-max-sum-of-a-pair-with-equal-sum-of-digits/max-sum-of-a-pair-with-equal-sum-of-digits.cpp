class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int max[82] = {0}; // Store max number for each digit sum (0-81)
        int ans = -1;

        for (int x : nums) {
            int sum = 0, temp = x;

            // calculate digit sum...
            while (temp != 0) {
                sum += temp % 10;
                temp /= 10;
            }
            // Update max pair sum
            if (max[sum] != 0)
                ans = std::max(ans, x + max[sum]);

            // Update max number for sum
            max[sum] = std::max(max[sum], x);
        }
        return ans;
    }
};
