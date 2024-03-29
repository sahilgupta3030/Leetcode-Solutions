class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxnum = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        long long ans = 0;
        int count = 0, j = 0;
        for (int x : nums) {
            while (j < n && count < k) {
                count += (nums[j++] == maxnum);
            }
            if (count < k) {
                break;
            }
            ans += n - j + 1;
            count -= x == maxnum;
        }
        return ans;
    }
};