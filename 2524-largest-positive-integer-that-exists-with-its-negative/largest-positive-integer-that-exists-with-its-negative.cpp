class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;

        unordered_set<int> seen; // store seen numbers.

        for (const int num : nums)
            // if the negative of the curr number is already seen.
            if (seen.count(-num))
                ans = max(ans, abs(num));
            else
                seen.insert(num); // if not seen, add num to the set.

        return ans;
    }
};