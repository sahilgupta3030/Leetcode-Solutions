class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> seen;

        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (seen.find(nums[right]) != seen.end()) {
                return true;
            }
            seen.insert(nums[right]);

            // shrink window when size exceeds k
            if (right - left >= k) {
                seen.erase(nums[left]);
                left++; 
            }
        }

        return false;
    }
};
