class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> count;
        int result = 0;

        // Loop through all pairs (i, j) where i > j
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                // Calculate product of pair
                int product = nums[i] * nums[j];

                // If this product was seen before...
                // ..add 8 times its count to the result
                result += count[product] * 8;

                // Increase the count of this product in the map
                count[product]++;
            }
        }
        return result;
    }
};
