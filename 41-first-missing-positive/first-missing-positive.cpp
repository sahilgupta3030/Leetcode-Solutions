class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        // Mark elements that are out of range or negative with 0
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = 0;
            }
        }
        
        // Place each number at its correct index if possible
        for (int i = 0; i < n; ++i) {
            while (nums[i] != 0 && nums[i] != i + 1) {
                int correct_index = nums[i] - 1;
                // Avoid infinite loops by checking if swapping is needed
                if (nums[i] == nums[correct_index]) {
                    break;
                }
                swap(nums[i], nums[correct_index]);
            }
        }
        
        // Find the first missing positive integer
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        // If all integers are present, return the next positive integer
        return n + 1;
    }
};
