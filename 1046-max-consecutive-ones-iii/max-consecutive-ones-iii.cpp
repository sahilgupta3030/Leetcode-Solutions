// SLIDING WINDOW
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;

        int countZero = 0; // count of zeros in current window
        int ans = 0;

        while (j < n) {

            // if zero encounters...
            if (nums[j] == 0) {
                countZero++; // increment zero count if encountered
            }
            while (countZero > k) {
                if (nums[i] == 0) {
                    countZero--;
                }
                i++; // adjust window
            }

            ans = max(ans, j - i + 1); // update answer
            j++;                       // move right pointer
        }
        return ans;
    }
};
