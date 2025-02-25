class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        // constexpr int kMod = 1'000'000'007;
        #define kMod 1000000007

        long ans = 0;
        int evenCount = 1;
        int oddCount = 0;

        int prefixSum = 0;

        for (int num : arr) {
            prefixSum += num;

            if (prefixSum % 2 == 0) {
                ans = (ans + oddCount) % kMod;
                evenCount++;
            } else {
                ans = (ans + evenCount) % kMod;
                oddCount++;
            }
        }

        return ans;
    }
};
