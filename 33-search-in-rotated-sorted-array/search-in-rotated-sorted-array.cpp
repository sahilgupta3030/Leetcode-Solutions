class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;

            // Check which side is sorted
            if (nums[left] <= nums[mid]) { // Left side is sorted
                if (nums[left] <= target && target < nums[mid])
                    right = mid - 1; // Search in the left sorted side
                else
                    left = mid + 1; // Search in the right side
            } else { // Right side is sorted
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1; // Search in the right sorted side
                else
                    right = mid - 1; // Search in the left side
            }
        }
        return -1; // Element not found
    }
};
