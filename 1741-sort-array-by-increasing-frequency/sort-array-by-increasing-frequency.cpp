class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> umap;

        // Count frequencies of each number
        for (auto x : nums) {
            umap[x]++;
        }

        // LAMBDA FUNCTION...

        // Sort nums based on frequency, then by value
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            return umap[a] != umap[b] ? umap[a] < umap[b] : a > b;
        });

        return nums;
    }
};