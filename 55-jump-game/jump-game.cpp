class Solution {
public:
    bool canJump(vector<int>& nums) {
        int finalPosition = nums.size() - 1;

        // Start with the second last index
        for (int idx = nums.size() - 2; idx >= 0; idx--) {
            
            // If you can reach the final position from this index
            // update the final position flag
            if (idx + nums[idx] >= finalPosition) {
                finalPosition = idx;
            }
        }
        return finalPosition == 0;
    }
};
