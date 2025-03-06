class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), l = 0, r = 0, ans = 0;
        int countZero = 0;

        for (; r < n; r++) {
            if (nums[r] == 0)
                countZero++;
            for (; countZero > 1; l++) {
                if (nums[l] == 0)
                    countZero--;
            }
            ans = max(ans, r - l + 1);
        }
        return ans - 1;
    }
};