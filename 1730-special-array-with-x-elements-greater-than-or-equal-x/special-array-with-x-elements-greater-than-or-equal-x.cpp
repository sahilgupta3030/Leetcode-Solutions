class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int x = 1; x <= n; ++x) {
            // Find the first element that is not less than x
            auto firstNotLess = lower_bound(nums.begin(), nums.end(), x);

            // Count the number of elements greater than or equal to x
            int count = n - (firstNotLess - nums.begin());

            if (x == count) {
                return x;
            }
        }
        return -1;
    }
};