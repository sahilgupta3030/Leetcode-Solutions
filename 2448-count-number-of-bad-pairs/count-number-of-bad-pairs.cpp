class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long badPairs = 0;
        unordered_map<int, int> diffCount; // Store frequency of (nums[i] - i)

        for (int i = 0; i < nums.size(); i++) {
            int diff = nums[i] - i;          // Compute difference
            badPairs += i - diffCount[diff]; // Count bad pairs
            diffCount[diff]++; // Update frequency of this difference
        }

        return badPairs;
    }
};
