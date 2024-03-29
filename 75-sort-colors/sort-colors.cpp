class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        int left = 0, right = nums.size() - 1, curr = 0;

        while (curr <= right) {
            if (nums[curr] == 0) {
                std::swap(nums[left], nums[curr]);
                left++;
                curr++;
            } else if (nums[curr] == 2) {
                std::swap(nums[curr], nums[right]);
                right--;
            } else {
                curr++;
            }
        }
    }
};