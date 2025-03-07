class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int left = 0, right = 0;
        int n = nums.size();
        int sum = 0;
        int minimalAns = INT_MAX;

        for (right; right < n; right++) {
            sum += nums[right];
            // shrink the window
            while (sum >= target) {
                minimalAns = min(minimalAns, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return (minimalAns == INT_MAX) ? 0 : minimalAns;
    }
};