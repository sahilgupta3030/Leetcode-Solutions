// Linked List Cycle method OR Tortoise method..
// Refer: takeuforward
// https://youtu.be/32Ll35mhWg0?si=DFhArrJRUDPMGXUa

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Move slow ptr 1 step and fast ptr 2 steps until they meet
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Find the entrance of the cycle
        fast = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
