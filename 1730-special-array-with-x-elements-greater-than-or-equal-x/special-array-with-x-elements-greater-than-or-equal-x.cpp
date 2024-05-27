class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int x = 1; x <= n; ++x) {
            auto it = lower_bound(nums.begin(), nums.end(), x);
            int count = n - (it - nums.begin());
            if (x == count) {
                return x;
            }
        }
        return -1;
    }
};